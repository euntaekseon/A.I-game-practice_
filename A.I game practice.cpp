#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bangtal>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace bangtal;

ObjectPtr rule[6], rule_image[6], start[6];
ObjectPtr challenge_button, practice_button, off, info, back, mode_info;
ScenePtr practice_scene = Scene::create("", "Images/prac_back.png");
ScenePtr main_scene = Scene::create("", "Images/main_background.png");
ScenePtr challenge_show = Scene::create("", "Images/chall_back.png");
ScenePtr prac_end = Scene::create("", "Images/back_ground.png");
ScenePtr com_chall = Scene::create("", "Images/com_chall.png");
ObjectPtr next = Object::create("Images/next_chall.png", challenge_show, 500, 550), retry = Object::create("Images/restart.png", challenge_show, 500, 550);
ObjectPtr yes_play_song = 0; ObjectPtr no_play_song = 0;
SoundPtr song = 0; SoundPtr song_end = 0;
ObjectPtr flag = Object::create("Images/red-flag.png", challenge_show, 1170, 395);


auto challenger = Object::create("Images/challenger.png", challenge_show, 0, 100);
int sound_check = 1; //1 on, 0 off
int x[7] = { 0,120,340,460,580,810,1030 };
int y[7] = { 80,80,180,180,180,290,395 };
auto restart_button = Object::create("Images/restart.png", prac_end, 520, 350);
auto select = Object::create("Images/select_game.png", prac_end, 520, 450);
char introduce_object[70];
int intro_on = 0;
int intro_on_num = 0;
int info_on = 0;
int k;

void song_object()
{
    yes_play_song = Object::create("Sound/Play_Song_Yes.png", main_scene, 1160, 480); yes_play_song->setScale(0.5);
    yes_play_song->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->play(true);
        yes_play_song->hide();
        no_play_song->show();
        sound_check = 1;
        return true;
        });
    no_play_song = Object::create("Sound/Play_Song_No.png", main_scene, 1160, 480); no_play_song->setScale(0.5);
    no_play_song->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->stop();
        no_play_song->hide();
        yes_play_song->show();
        sound_check = 0;
        return true;
        });
}

void set_end() {
    restart_button->setScale(0.12);
    select->setScale(0.1);
}
bool challenge = false;

void success(int n) {
    k = n + 1;
    challenger->locate(challenge_show, x[n], y[n]);
    auto move_timer = Timer::create(1);
    move_timer->start();
    move_timer->setOnTimerCallback([&](auto)->bool {
        challenger->locate(challenge_show, x[k], y[k]);
        showMessage("게임을 통과하셨습니다!!");
        return true;
        });
    next->show();
    next->setScale(0.1);
    retry->hide();
}

void fail(int n) {
    challenger->locate(challenge_show, x[n], y[n]);
    retry->show();
    retry->setScale(0.1);
    next->hide();
}

int choose_index(ObjectPtr o) {
    for (int i = 0; i < 6; i++) {
        if (rule[i] == o) return i;
        else if (start[i] == o) return i;
    }
    return -1;
}

std::string set_explain_image(int index) {
    return "게임 설명/game_rule_" + std::to_string(index) + ".png";
}

///////////////////////////////////////////////////////////////////////////////////////////////// 0번 게임 함수

TimerPtr timer1_0, timer2_0, timer_inst_0;
ScenePtr scene_0;
ObjectPtr start1_0 = 0;
ObjectPtr start2_0 = 0;
ObjectPtr end_0 = 0;
ObjectPtr yes_play_song_0 = 0;
ObjectPtr no_play_song_0 = 0;
ObjectPtr placement_0[12] = { 0, };

int arr_20_0[20] = { 0, }, result_true_0[20] = { 0, }, result_your_0[40] = { 0, };
int trial_0 = 20; int count_0 = 0;
int choose_num_0 = 0; int num_right_0 = 0;

void song_object_0()
{
    yes_play_song_0 = Object::create("Sound/Play_Song_Yes.png", scene_0, 1150, 600); yes_play_song_0->setScale(0.5);
    yes_play_song_0->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->play(true);
        yes_play_song_0->hide();
        no_play_song_0->show();
        sound_check = 1;
        return true;
        });
    no_play_song_0 = Object::create("Sound/Play_Song_No.png", scene_0, 1150, 600); no_play_song_0->setScale(0.5);
    no_play_song_0->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->stop();
        no_play_song_0->hide();
        yes_play_song_0->show();
        sound_check = 0;
        return true;
        });
}

int index_to_x_0(int index)
{
    return (350 + 150 * (index % 4));
}
int index_to_y_0(int index)
{
    return (450 - 170 * (index / 4));
}

void makearray_start_0()
{
    printf("\n\n\n");
    printf("======================================================================");
    printf("\n\n\n");
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 20; i++)
    {
        arr_20_0[i] = rand() % 12;
        if (i > 3)
        {
            if (choose_num_0 == 2)
            {
                if (arr_20_0[i] % 5 == 0)
                    arr_20_0[i] = arr_20_0[i - 2];
            }
            if (choose_num_0 == 3)
            {
                if (arr_20_0[i] % 5 == 0)
                    arr_20_0[i] = arr_20_0[i - 3];
            }
        }
    }

    trial_0 = 20;
    timer1_0->set(3.0f); timer1_0->start();
}

void makeresult_0()
{
    start1_0->show(); start2_0->show();
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr_20_0[i] + 1);
    }
    printf("\n\n");

    if (choose_num_0 == 2)
    {
        num_right_0 = 0;
        printf("Correct Answer is :\n\n");
        for (int i = 2; i < 20; i++)
        {
            if (arr_20_0[i] == arr_20_0[i - 2])
                result_true_0[i - 2] = 1;
            else
                result_true_0[i - 2] = 2;
            printf(" %d ", result_true_0[i - 2]);
        } // result_true 에 0~17 값이 저장된다.

        printf("\nYour Answer is :\n");
        for (int i = 0; i < 35; i++)
        {
            if (i % 2 == 0)
            {
                printf(" %d ", result_your_0[i]);
            }
        }
        for (int i = 0; i < 18; i++)
        {
            if (result_true_0[i] == result_your_0[2 * i])
            {
                num_right_0++;
            }
        }
        char message_in[100];
        sprintf(message_in, "Your score is %d out of 18 !!!", num_right_0);
        showMessage(message_in);
        hideTimer();
        if (challenge) {
            if (num_right_0 > 12) {
                success(0);
                challenge_show->enter();
                next->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                    scene_1->enter();
                    init_game_1();
                    return true;
                    });
            }
            else {
                fail(0);
                challenge_show->enter();
                retry->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                    scene_0->enter();
                    return true;
                    });
            }
        }
        else {
            prac_end->enter();
            set_end();
            select->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                practice_scene->enter();
                return true;
                });
            restart_button->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                scene_0->enter();
                return true;
                });
        }
    }

    if (choose_num_0 == 3)
    {
        num_right_0 = 0;
        printf("Correct Answer is :\n\n");
        for (int i = 3; i < 20; i++)
        {
            if (arr_20_0[i] == arr_20_0[i - 3])
                result_true_0[i - 3] = 1;
            else
                result_true_0[i - 3] = 2;
            printf(" %d ", result_true_0[i - 3]);
        } // result_true 에 0~16 값이 저장된다.
        printf("\nYour Answer is :\n");
        for (int i = 0; i < 33; i++)
        {
            if (i % 2 == 0)
            {
                printf(" %d ", result_your_0[i]);
            }
        }
        for (int i = 0; i < 17; i++)
        {
            if (result_true_0[i] == result_your_0[2 * i])
            {
                num_right_0++;
            }
        }
        char message_in[100];
        sprintf(message_in, "Your score is %d out of 17 !!!", num_right_0);
        showMessage(message_in);
        hideTimer();
        if (challenge) {
            if (num_right_0 > 12) {
                success(0);
                challenge_show->enter();
                next->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                    scene_1->enter();
                    init_game_1();
                    return true;
                    });
            }
            else {
                fail(0);
                challenge_show->enter();
                retry->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                    scene_0->enter();
                    return true;
                    });
            }
        }
        else {
            prac_end->enter();
            set_end();
            select->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                practice_scene->enter();
                return true;
                });
            restart_button->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                scene_0->enter();
                return true;
                });
        }
    }
}

void reset_0()
{
    trial_0 = 20; count_0 = 0;
    timer_inst_0 = Timer::create(63.0f);
    timer_inst_0->setOnTimerCallback([&](auto)->bool {
        makeresult_0();
        return true;
        });
}

void init_game_0()
{
    song_object_0();
    if (sound_check == 1)
    {
        yes_play_song_0->hide();
        no_play_song_0->show();
    }
    else
    {
        yes_play_song_0->show();
        no_play_song_0->hide();
    }

    scene_0->setOnKeyboardCallback([&](ScenePtr scene_0, KeyCode key_0, bool pressed)->bool {
        if (count_0 < 40)
        {
            if (key_0 == KeyCode::KEY_LEFT_ARROW)
                result_your_0[count_0] = 1;
            if (key_0 == KeyCode::KEY_RIGHT_ARROW)
                result_your_0[count_0] = 2;
            count_0++;
        }

        return true;
        });

    timer1_0 = Timer::create(3.0f);
    timer1_0->setOnTimerCallback([&](auto)->bool {
        if (trial_0 > 0) {
            timer1_0->set(3.0f);
            timer1_0->start();
            placement_0[arr_20_0[20 - trial_0]]->hide();
            timer2_0->set(1.0f); timer2_0->start();
        }
        trial_0--;
        return true;
        });

    timer2_0 = Timer::create(1.0f);
    timer2_0->setOnTimerCallback([&](auto)->bool {
        placement_0[arr_20_0[20 - trial_0 - 1]]->show();
        return true;
        });

    start1_0 = Object::create("Images0/2_back_start.png", scene_0, 30, 130);
    start1_0->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        choose_num_0 = 2; makearray_start_0();
        reset_0(); timer_inst_0->start(); showTimer(timer_inst_0);
        start1_0->hide(); start2_0->hide();
        return true;
        });

    start2_0 = Object::create("Images0/3_back_start.png", scene_0, 30, 50);
    start2_0->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        choose_num_0 = 3; makearray_start_0();
        reset_0(); timer_inst_0->start(); showTimer(timer_inst_0);
        start1_0->hide(); start2_0->hide();;
        return true;
        });

    end_0 = Object::create("Images0/end.png", scene_0, 1100, 50);
    end_0->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        endGame();
        return true;
        });

    for (int i = 0; i < 12; i++)
    {
        placement_0[i]->show();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////// 1번 게임 함수

ScenePtr scene_1;
ObjectPtr easy_1, hard_1, button_1[3], board1_1[3][4], board2_1[3][5], restart_1;
ObjectPtr yes_play_song_1 = 0;
ObjectPtr no_play_song_1 = 0;

int mode_1;//4 - easy, 5 - hard
int count_1 = 0, limit_1;//count - 이용자, limit - 최대 이동 가능 횟수
int arr1_1[3][4] = { 0 }, arr2_1[3][5] = { 0 }, order_1[3];//arr - 이동가능한 원반 위치 알려줌, order - 원반이 이동할 때 세로 위치 알려줌
char path_1[50] = { 0 }, result_1[50] = { 0 };
int flag_1 = 0, disk_1 = -1;//flag가 1이라서 원반을 보여줄 때, 보여줘야 할 disk의 위치(= j값 저장용)

void song_object_1()
{
    yes_play_song_1 = Object::create("Sound/Play_Song_Yes.png", scene_1, 1150, 600); yes_play_song_1->setScale(0.5);
    yes_play_song_1->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->play(true);
        yes_play_song_1->hide();
        no_play_song_1->show();
        sound_check = 1;
        return true;
        });
    no_play_song_1 = Object::create("Sound/Play_Song_No.png", scene_1, 1150, 600); no_play_song_1->setScale(0.5);
    no_play_song_1->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->stop();
        no_play_song_1->hide();
        yes_play_song_1->show();
        sound_check = 0;
        return true;
        });
}

int index_to_x_1(int index) {
    return 215 - (index * 17);
}

int index_to_y_1(int index, int num) {
    if (num == 4) {
        return 440 - (index * 50) - 50;
    }
    else if (num == 5) {
        return 440 - (index * 50);
    }
}

int button_x_1(int index) {
    return (index * 390) + 200;
}

bool check_finish_1(int num) {

    int i_1;
    if (num == 4) {
        for (i_1 = 0; i_1 < num; i_1++) {
            if (arr1_1[2][i_1] == 0) return false;
        }
        if (arr1_1[2][i_1] == 1) return true;//끝까지 다 1이 채워졌으면 성공
    }
    else if (num == 5) {
        for (i_1 = 0; i_1 < num; i_1++) {
            if (arr2_1[2][i_1] == 0) return false;
        }
        if (arr2_1[2][i_1] == 1) return true;//끝까지 다 1이 채워졌으면 성공
    }
}

void start_game_1() {//실제 원반이 이동되는 함수 - 실질적 게임 진행 화면
    restart_1->show();
    restart_1->setScale(0.8f);
    restart_1->setOnMouseCallback([&](auto, auto, auto, auto)->bool {//원반, restart hide + init으로 돌아감 
        for (int i_1 = 0; i_1 < 3; i_1++) {
            if (mode_1 == 4) {
                for (int j_1 = 0; j_1 < 4; j_1++) {
                    board1_1[i_1][j_1]->hide();
                }
            }
            else if (mode_1 == 5) {
                for (int k_1 = 0; k_1 < 5; k_1++) {
                    board2_1[i_1][k_1]->hide();
                }
            }
            button_1[i_1]->hide();
        }
        restart_1->hide();
        init_game_1();
        return true;
        });

    //원반 이동
    for (int i_1 = 0; i_1 < 3; i_1++) {
        button_1[i_1]->setOnMouseCallback([&, i_1](auto, auto, auto, auto)->bool {
            int j_1; int check_1 = -1;

            if (mode_1 == 4) {
                if (flag_1 == 0) {//원반 줍고(hide), 다음 버튼 클릭
                    for (j_1 = 0; j_1 < 4; j_1++) {//최상위에 있는 원반 찾음
                        if (arr1_1[i_1][j_1] == 1) {
                            arr1_1[i_1][j_1] = 0;
                            board1_1[i_1][j_1]->hide();
                            flag_1 = 1; disk_1 = j_1; order_1[i_1] += 1;
                            break;
                        }
                    }
                }
                else if (flag_1 == 1) {//원반 보여줄 차례 - 위에 arr에 이미 1이 있다면 메세지로 옮길 수 없습니다 출력
                    for (j_1 = 0; j_1 < disk_1; j_1++) {
                        if (arr1_1[i_1][j_1] == 1) {//원반을 옮기지 못 하는 경우
                            showMessage("원반을 옮길 수 없습니다.");
                            break;
                        }
                    }
                    if (arr1_1[i_1][j_1] == 0) {
                        arr1_1[i_1][disk_1] = 1;
                        board1_1[i_1][disk_1]->locate(scene_1, index_to_x_1(disk_1) + 370 * i_1, index_to_y_1(order_1[i_1], 4));
                        board1_1[i_1][disk_1]->show();
                        order_1[i_1] -= 1;//다음에 위치할 축으로 위치 조정
                        flag_1 = 0; disk_1 = -1; count_1++;
                        printf("\nnow count: %d", count_1);
                    }
                }
            }

            else if (mode_1 == 5) {
                if (flag_1 == 0) {//원반 줍고(hide), 다음 버튼 클릭
                    for (j_1 = 0; j_1 < 5; j_1++) {//최상위에 있는 원반 찾음

                        if (arr2_1[i_1][j_1] == 1) {
                            arr2_1[i_1][j_1] = 0;
                            board2_1[i_1][j_1]->hide();
                            flag_1 = 1; disk_1 = j_1; order_1[i_1] += 1;
                            break;
                        }
                    }
                }
                else if (flag_1 == 1) {//원반 보여줄 차례 - 위에 arr에 이미 1이 있다면 메세지로 옮길 수 없습니다 출력
                    for (j_1 = 0; j_1 < disk_1; j_1++) {
                        if (arr2_1[i_1][j_1] == 1) {//원반을 옮기지 못 하는 경우
                            showMessage("원반을 옮길 수 없습니다.");
                            break;
                        }
                    }
                    if (arr2_1[i_1][j_1] == 0) {
                        arr2_1[i_1][disk_1] = 1;
                        board2_1[i_1][disk_1]->locate(scene_1, index_to_x_1(disk_1) + 370 * i_1, index_to_y_1(order_1[i_1], 5));
                        board2_1[i_1][disk_1]->show();
                        order_1[i_1] -= 1;//다음에 위치할 축으로 위치 조정
                        flag_1 = 0; disk_1 = -1; count_1++;
                        printf("\nnow count: %d", count_1);
                    }
                }

            }

            if (check_finish_1(4) || check_finish_1(5)) {
                sprintf(result_1, "성공!(이동횟수: %d)", count_1);
                printf("\n\n\n");
                printf("======================================================================");
                printf("\n\n\n");
                showMessage(result_1);
                if (challenge) {
                    challenge_show->enter();
                    success(1);
                    next->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                        scene_2->enter();
                        init_game_2();
                        return true;
                        });
                }
                else {
                    prac_end->enter();
                    set_end();
                    select->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                        for (int i_1 = 0; i_1 < 3; i_1++) {
                            if (mode_1 == 4) {
                                for (int j_1 = 0; j_1 < 4; j_1++) {
                                    board1_1[i_1][j_1]->hide();
                                }
                            }
                            else if (mode_1 == 5) {
                                for (int k_1 = 0; k_1 < 5; k_1++) {
                                    board2_1[i_1][k_1]->hide();
                                }
                            }
                            button_1[i_1]->hide();
                        }
                        restart_1->hide();
                        practice_scene->enter();
                        return true;
                        });
                    restart_button->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                        for (int i_1 = 0; i_1 < 3; i_1++) {
                            if (mode_1 == 4) {
                                for (int j_1 = 0; j_1 < 4; j_1++) {
                                    board1_1[i_1][j_1]->hide();
                                }
                            }
                            else if (mode_1 == 5) {
                                for (int k_1 = 0; k_1 < 5; k_1++) {
                                    board2_1[i_1][k_1]->hide();
                                }
                            }
                            button_1[i_1]->hide();
                        }
                        restart_1->hide();
                        init_game_1();
                        return true;
                        });
                }
            }
            if (count_1 > limit_1) {
                sprintf(result_1, "이동횟수 초과(이동횟수: %d번)", count_1);
                printf("\n\n\n");
                printf("======================================================================");
                printf("\n\n\n");
                showMessage(result_1);
                if (challenge) {
                    fail(1);
                    challenge_show->enter();
                    retry->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                        for (int i_1 = 0; i_1 < 3; i_1++) {
                            if (mode_1 == 4) {
                                for (int j_1 = 0; j_1 < 4; j_1++) {
                                    board1_1[i_1][j_1]->hide();
                                }
                            }
                            else if (mode_1 == 5) {
                                for (int k_1 = 0; k_1 < 5; k_1++) {
                                    board2_1[i_1][k_1]->hide();
                                }
                            }
                            button_1[i_1]->hide();
                        }
                        restart_1->hide();
                        scene_1->enter();
                        init_game_1();
                        return true;
                        });
                }
                else {
                    prac_end->enter();
                    set_end();
                    restart_button->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                        for (int i_1 = 0; i_1 < 3; i_1++) {
                            if (mode_1 == 4) {
                                for (int j_1 = 0; j_1 < 4; j_1++) {
                                    board1_1[i_1][j_1]->hide();
                                }
                            }
                            else if (mode_1 == 5) {
                                for (int k_1 = 0; k_1 < 5; k_1++) {
                                    board2_1[i_1][k_1]->hide();
                                }
                            }
                            button_1[i_1]->hide();
                        }
                        restart_1->hide();
                        scene_1->enter();
                        init_game_1();
                        return true;
                        });
                    select->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                        for (int i_1 = 0; i_1 < 3; i_1++) {
                            if (mode_1 == 4) {
                                for (int j_1 = 0; j_1 < 4; j_1++) {
                                    board1_1[i_1][j_1]->hide();
                                }
                            }
                            else if (mode_1 == 5) {
                                for (int k_1 = 0; k_1 < 5; k_1++) {
                                    board2_1[i_1][k_1]->hide();
                                }
                            }
                            button_1[i_1]->hide();
                        }
                        restart_1->hide();
                        practice_scene->enter();
                        return true;
                        });
                }
            }
            return true;
            });
    }

}

void init_game_1() {//start_game함수에서 restart를 눌러 초기화 된 상태 - 게임 실행 전 세팅하는 부분
    showMessage("게임 모드를 선택하세요");
    song_object_1();
    if (sound_check == 1)
    {
        yes_play_song_1->hide();
        no_play_song_1->show();
    }
    else
    {
        yes_play_song_1->show();
        no_play_song_1->hide();
    }
    //게임에 사용할 변수들 초기화 - restart될 경우까지 생각해서 init_game에서 초기화
    count_1 = 0; flag_1 = 0; disk_1 = -1;
    for (int i_1 = 0; i_1 < 3; i_1++) {//arr1/arr2 싹 다 0으로 채움
        for (int j_1 = 0; j_1 < 4; j_1++) {
            arr1_1[i_1][j_1] = 0;
        }
        for (int k_1 = 0; k_1 < 5; k_1++) {
            arr2_1[i_1][k_1] = 0;
        }
    }

    //easy, hard -> 원반, button 생성 -> 일단 생성하고, start_game에서 보여줌
    for (int i_1 = 0; i_1 < 3; i_1++) {
        sprintf(path_1, "Images1/버튼%d.jpg", i_1 + 1);
        button_1[i_1] = Object::create(path_1, scene_1, button_x_1(i_1), 120);
        button_1[i_1]->setScale(1.7f);
        button_1[i_1]->hide();
    }

    easy_1 = Object::create("Images1/easy.jpg", scene_1, 140, 250);
    easy_1->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        scene_1->setImage("Images1/하노이배경.jpg");
        easy_1->hide(); hard_1->hide();
        mode_1 = 4; limit_1 = 18;
        order_1[0] = -1; order_1[1] = 3; order_1[2] = 3;
        for (int i_1 = 0; i_1 < 3; i_1++) {//일단 arr1 싹 다 0으로 채움
            button_1[i_1]->show();//button 보여주기
        }
        for (int i_1 = 0; i_1 < 4; i_1++) {//배열 첫 번째는 1로 채우고, 두번째/세번째는 0으로
            arr1_1[0][i_1] = 1;
            sprintf(path_1, "Images1/원반%d.png", i_1 + 1);
            board1_1[0][i_1] = Object::create(path_1, scene_1, index_to_x_1(i_1), index_to_y_1(i_1, 4));
            board1_1[1][i_1] = Object::create(path_1, scene_1, index_to_x_1(i_1) + 370, index_to_y_1(i_1, 4));
            board1_1[2][i_1] = Object::create(path_1, scene_1, index_to_x_1(i_1) + 740, index_to_y_1(i_1, 4));
            board1_1[1][i_1]->hide(); board1_1[2][i_1]->hide();
        }
        showMessage("아래 버튼을 클릭해서 원반을 움직이세요(1번에서 3번으로)");
        printf("\neasy mode start");
        start_game_1();
        return true;
        });

    hard_1 = Object::create("Images1/hard.jpg", scene_1, 820, 250);
    hard_1->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        scene_1->setImage("Images1/하노이배경.jpg");
        easy_1->hide(); hard_1->hide();
        mode_1 = 5; limit_1 = 37;
        order_1[0] = -1; order_1[1] = 4; order_1[2] = 4;
        for (int i_1 = 0; i_1 < 3; i_1++) {//button 보여주기
            button_1[i_1]->show();//button 보여주기
        }
        for (int i_1 = 0; i_1 < 5; i_1++) {//배열 첫 번째는 1로 채우고, 두번째/세번째는 0으로
            arr2_1[0][i_1] = 1;
            sprintf(path_1, "Images1/원반%d.png", i_1 + 1);
            board2_1[0][i_1] = Object::create(path_1, scene_1, index_to_x_1(i_1), index_to_y_1(i_1, 5));
            board2_1[1][i_1] = Object::create(path_1, scene_1, index_to_x_1(i_1) + 370, index_to_y_1(i_1, 5));
            board2_1[2][i_1] = Object::create(path_1, scene_1, index_to_x_1(i_1) + 740, index_to_y_1(i_1, 5));
            board2_1[1][i_1]->hide(); board2_1[2][i_1]->hide();
        }
        showMessage("아래 버튼을 클릭해서 원반을 움직이세요(1번에서 3번으로)");
        printf("\nhard mode start");
        start_game_1();
        return true;
        });

    restart_1 = Object::create("Images1/restart.png", scene_1, 900, 600);
    restart_1->setScale(1.2f);
    restart_1->setOnMouseCallback([&](auto, auto, auto, auto)->bool {//원반, restart hide + init으로 돌아감 
        for (int i_1 = 0; i_1 < 3; i_1++) {
            if (mode_1 == 4) {
                for (int j_1 = 0; j_1 < 4; j_1++) {
                    board1_1[i_1][j_1]->hide();
                }
            }
            else if (mode_1 == 5) {
                for (int k_1 = 0; k_1 < 5; k_1++) {
                    board2_1[i_1][k_1]->hide();
                }
            }
            button_1[i_1]->hide();
        }
        restart_1->hide();
        init_game_1();
        return true;
        });
    restart_1->hide();
    scene_1->setImage("Images1/배경.jpg");
}

///////////////////////////////////////////////////////////////////////////////////////////////// 2번 게임 함수

TimerPtr timer_finish_2;
ScenePtr scene_2;
ObjectPtr restart_2 = 0;
ObjectPtr end_2 = 0;
ObjectPtr notice_2 = 0;
ObjectPtr placement_2[7][7] = { 0, };
SoundPtr song_2 = 0;
ObjectPtr yes_play_song_2 = 0;
ObjectPtr no_play_song_2 = 0;
int check_start_2 = 0;

void song_object_2()
{
    yes_play_song_2 = Object::create("Sound/Play_Song_Yes.png", scene_2, 1150, 600); yes_play_song_2->setScale(0.5);
    yes_play_song_2->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->play(true);
        yes_play_song_2->hide();
        no_play_song_2->show();
        sound_check = 1;
        return true;
        });
    no_play_song_2 = Object::create("Sound/Play_Song_No.png", scene_2, 1150, 600); no_play_song_2->setScale(0.5);
    no_play_song_2->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->stop();
        no_play_song_2->hide();
        yes_play_song_2->show();
        sound_check = 0;
        return true;
        });
}

int arr_20_1_2[21][3] = { 0, }, arr_20_2_2[21][3] = { 0, }, result_true_2[21] = { 0, }, result_your_2[45] = { 0, }, result_2[21] = { 0, };
int trial_2 = 20; int count_2 = 0;
int choose_num_2 = 0; int num_right_2 = 0;

void makearray_start_2() {
    printf("\n\n\n");
    printf("======================================================================");
    printf("\n\n\n");

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr_20_1_2[i][j] = rand() % 7;
            arr_20_2_2[i][j] = rand() % 7;
            if (arr_20_1_2[i][j] == arr_20_2_2[i][j])
            {
                arr_20_2_2[i][j] = arr_20_2_2[i][j] + 1;
                arr_20_2_2[i][j] = arr_20_2_2[i][j] % 7;
            }
        }
        if ((rand() % 3) == 0)
        {
            arr_20_1_2[i][0] = arr_20_2_2[i][1];
        }
    }
}


void makeresult_2() {
    check_start_2 = 0;
    printf("\n\n");
    num_right_2 = 0;

    for (int i = 0; i < 20; i++)
    {
        if (arr_20_1_2[i][0] == arr_20_2_2[i][1])
        {
            result_true_2[i] = 1;
        }
        else
        {
            result_true_2[i] = 2;
        }

        if (result_true_2[i] == result_your_2[i * 2])
        {
            printf("O ");
            num_right_2++;
        }
        else
        {
            printf("X ");
        }
    }
    printf("\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", result_true_2[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", result_your_2[i * 2]);
    }

    char message_in_2[100];
    sprintf(message_in_2, "Your score is %d out of 20 !!!", num_right_2);
    showMessage(message_in_2);
    if (challenge) {
        challenge_show->enter();
        if (num_right_2 > 14) {
            success(2);
            next->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                scene_3->enter();
                init_game_3();
                return true;
                });
        }
        else {
            fail(2);
            retry->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                reset_2();
                makearray_start_2();
                placement_2[arr_20_1_2[0][0]][arr_20_1_2[0][1]]->show();
                placement_2[arr_20_1_2[0][0]][arr_20_1_2[0][1]]->locate(scene_2, 200, 250);
                placement_2[arr_20_2_2[0][0]][arr_20_2_2[0][1]]->show();
                placement_2[arr_20_2_2[0][0]][arr_20_2_2[0][1]]->locate(scene_2, 700, 250);
                scene_2->enter();
                restart_2->hide();
                check_start_2 = 1;
                return true;
                });
        }
    }
    else {
        prac_end->enter();
        set_end();
        restart_button->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            reset_2();
            makearray_start_2();
            placement_2[arr_20_1_2[0][0]][arr_20_1_2[0][1]]->show();
            placement_2[arr_20_1_2[0][0]][arr_20_1_2[0][1]]->locate(scene_2, 200, 250);
            placement_2[arr_20_2_2[0][0]][arr_20_2_2[0][1]]->show();
            placement_2[arr_20_2_2[0][0]][arr_20_2_2[0][1]]->locate(scene_2, 700, 250);
            scene_2->enter();
            restart_2->hide();
            check_start_2 = 1;
            return true;
            });

        select->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            reset_2();
            practice_scene->enter();
            return true;
            });
    }
}

void reset_2() {
    trial_2 = 20;
    count_2 = 0;
}

void init_game_2()
{
    song_object_2();
    if (sound_check == 1)
    {
        yes_play_song_2->hide();
        no_play_song_2->show();
    }
    else
    {
        yes_play_song_2->show();
        no_play_song_2->hide();
    }
    char path_2[50];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++)
        {
            sprintf(path_2, "Images2/%d_%d.png", i, j);
            placement_2[i][j] = Object::create(path_2, scene_2, 200, 250);
            placement_2[i][j]->setScale(2.0f);
            placement_2[i][j]->hide();
        }
    };

    scene_2->setOnKeyboardCallback([&](ScenePtr scene_2, KeyCode key_2, bool pressed)->bool {
        if (check_start_2 == 1)
        {
            if (count_2 < 40)
            {
                if (key_2 == KeyCode::KEY_LEFT_ARROW)
                {
                    result_your_2[count_2] = 1; //전환 show, hide
                }
                if (key_2 == KeyCode::KEY_RIGHT_ARROW)
                {
                    result_your_2[count_2] = 2; //전환 show, hide
                }
                int input_inst_2 = count_2 / 2 + 1;
                if (count_2 % 2 == 0)
                {
                    if (input_inst_2 >= 1)
                    {
                        placement_2[arr_20_1_2[input_inst_2 - 1][0]][arr_20_1_2[input_inst_2 - 1][1]]->hide();
                        placement_2[arr_20_2_2[input_inst_2 - 1][0]][arr_20_2_2[input_inst_2 - 1][1]]->hide();
                    }

                    placement_2[arr_20_1_2[input_inst_2][0]][arr_20_1_2[input_inst_2][1]]->show();
                    placement_2[arr_20_1_2[input_inst_2][0]][arr_20_1_2[input_inst_2][1]]->locate(scene_2, 200, 250);
                    placement_2[arr_20_2_2[input_inst_2][0]][arr_20_2_2[input_inst_2][1]]->show();
                    placement_2[arr_20_2_2[input_inst_2][0]][arr_20_2_2[input_inst_2][1]]->locate(scene_2, 700, 250);
                }
            }

            count_2++;

            if (count_2 == 39)
            {
                timer_finish_2->set(0.5); timer_finish_2->start();
            }
        }
        return true;
        });

    timer_finish_2 = Timer::create(0.5);
    timer_finish_2->setOnTimerCallback([&](auto)->bool {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++)
            {
                placement_2[i][j]->hide();
            }
        };
        makeresult_2();
        return true;
        });

    restart_2 = Object::create("Images2/start.png", scene_2, 1150, 150); restart_2->setScale(1.2f);
    restart_2->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        reset_2();
        makearray_start_2();
        check_start_2 = 1;
        placement_2[arr_20_1_2[0][0]][arr_20_1_2[0][1]]->show();
        placement_2[arr_20_1_2[0][0]][arr_20_1_2[0][1]]->locate(scene_2, 200, 250);
        placement_2[arr_20_2_2[0][0]][arr_20_2_2[0][1]]->show();
        placement_2[arr_20_2_2[0][0]][arr_20_2_2[0][1]]->locate(scene_2, 700, 250);
        restart_2->hide();
        return true;
        });
    restart_2->show();

    end_2 = Object::create("Images2/end.png", scene_2, 1150, 90); end_2->setScale(1.2f);
    end_2->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        endGame();
        return true;
        });
}

///////////////////////////////////////////////////////////////////////////////////////////////// 3번 게임 함수

ObjectPtr yes_play_song_3 = 0;
ObjectPtr no_play_song_3 = 0;
ScenePtr scene_3;

int correct_3 = 0, wrong_3 = 0;
int n_3 = n_3 = rand() % 2, m_3 = rand() % 2, i_3 = 0;
int x_3[2] = { 260,735 };
int y_3[2] = { 160,430 };
int X_3 = x_3[n_3], Y_3 = y_3[m_3];
int count_3 = 0;

void song_object_3()
{
    yes_play_song_3 = Object::create("Sound/Play_Song_Yes.png", scene_3, 1150, 600); yes_play_song_3->setScale(0.5);
    yes_play_song_3->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->play(true);
        yes_play_song_3->hide();
        no_play_song_3->show();
        sound_check = 1;
        return true;
        });
    no_play_song_3 = Object::create("Sound/Play_Song_No.png", scene_3, 1150, 600); no_play_song_3->setScale(0.5);
    no_play_song_3->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->stop();
        no_play_song_3->hide();
        yes_play_song_3->show();
        sound_check = 0;
        return true;
        });
}

//짝수인지 아닌지 모음인지 아닌지를 판별하는 정보를 가진 오브젝트 클래스
class problem_3 {
    bool even_3;
    bool collection_3;
    ObjectPtr num_3;
    ObjectPtr word_3;
public:
    problem_3() :even_3(false), collection_3(false) {};
    problem_3(bool a, bool b, ObjectPtr c, ObjectPtr d) : even_3(a), collection_3(b), num_3(c), word_3(d) {};
    void set_3(bool a, bool b, ObjectPtr c, ObjectPtr d) {
        even_3 = a; collection_3 = b;
        num_3 = c; word_3 = d;
    }
    void show_3() {
        num_3->show();
        word_3->show();
    }
    void hide_3() {
        num_3->hide();
        word_3->hide();
    }
    void locate_3(ScenePtr scene_3, int x_3, int y_3) {
        num_3->locate(scene_3, x_3, y_3);
        word_3->locate(scene_3, x_3 + 120, y_3);
    }
    bool Is_even_3() { return even_3; }
    bool Is_collection_3() { return collection_3; }
};
problem_3 prob_3[21];

bool Is_correct_3(int X, int Y, problem_3 p) {
    if (X == x_3[0] && Y == y_3[1]) {
        if (p.Is_even_3()) return false;
        else return true;
    }
    else if (X == x_3[0] && Y == y_3[0]) {
        if (p.Is_even_3()) return true;
        else return false;
    }
    else if (X == x_3[1] && Y == y_3[0]) {
        if (p.Is_collection_3()) return true;
        else return false;
    }
    else {
        if (p.Is_collection_3()) return false;
        else return true;
    }
}

void reset_3() {
    correct_3 = 0, wrong_3 = 0, count_3 = 0;
}

std::string returnresult_3(int index) {
    return "Your score is  " + std::to_string(index) + " of 20";
}

std::string prob_image1(int index) {
    return "Images3/숫자" + std::to_string(index) + ".png";
}

std::string prob_image2(int index) {
    return "Images3/글자" + std::to_string(index) + ".png";
}

void init_game_3() {
    scene_3->enter();
    song_object_3();
    if (sound_check == 1)
    {
        yes_play_song_3->hide();
        no_play_song_3->show();
    }
    else
    {
        yes_play_song_3->show();
        no_play_song_3->hide();
    }
    bool tf_3[2] = { true,false };
    //문제 21개 생성
    ObjectPtr num_3;
    ObjectPtr word_3;
    char path_3[70];
    for (int i_3 = 0; i_3 < 21; i_3++) {
        bool bool1_3, bool2_3;
        bool1_3 = tf_3[rand() % 2];
        bool2_3 = tf_3[rand() % 2];
        int n1_3, n2_3;
        n1_3 = rand() % 14;
        n2_3 = rand() % 5;
        if (bool1_3) {
            num_3 = Object::create(prob_image1(n2_3 + 5), scene_3, 0, 0);
        }
        else {
            num_3 = Object::create(prob_image1(n2_3), scene_3, 0, 0);
        }

        if (bool2_3) {
            word_3 = Object::create(prob_image2(n1_3 + 14), scene_3, 0, 0);
        }
        else {
            word_3 = Object::create(prob_image2(n1_3), scene_3, 0, 0);
        }
        num_3->setScale(0.8f);
        word_3->setScale(0.8f);
        prob_3[i_3].set_3(bool1_3, bool2_3, num_3, word_3);
        prob_3[i_3].hide_3();
    }
    printf("\n");
    auto right_button_3 = Object::create("Images3/같음.png", scene_3, 10, 50);
    auto wrong_button_3 = Object::create("Images3/다름.png", scene_3, 990, 50);

    correct_3 = 0; wrong_3 = 0;
    n_3 = n_3 = rand() % 2; m_3 = rand() % 2, i_3 = 0;
    X_3 = x_3[n_3]; Y_3 = y_3[m_3];
    count_3 = 0;

    prob_3[0].show_3();
    prob_3[0].locate_3(scene_3, X_3, Y_3);
    scene_3->setOnKeyboardCallback([&](ScenePtr scene_3, KeyCode key, bool pressed)->bool {
        if ((count_3 % 2) && (i_3 < 20))
        {
            if (key == KeyCode::KEY_LEFT_ARROW) {
                if (Is_correct_3(X_3, Y_3, prob_3[i_3])) {
                    correct_3++;
                    printf("%d : 0\n", i_3 + 1);
                }
                else {
                    wrong_3++;
                    printf("%d : X\n", i_3 + 1);
                }
                prob_3[i_3].hide_3();
                i_3++;
                n_3 = rand() % 2;
                m_3 = rand() % 2;
                X_3 = x_3[n_3];
                Y_3 = y_3[m_3];
                prob_3[i_3].show_3();
                prob_3[i_3].locate_3(scene_3, X_3, Y_3);
            }
            else if (key == KeyCode::KEY_RIGHT_ARROW) {
                if (Is_correct_3(X_3, Y_3, prob_3[i_3])) {
                    wrong_3++;
                    printf("%d : X\n", i_3 + 1);
                }
                else {
                    correct_3++;
                    printf("%d : 0\n", i_3 + 1);
                }
                prob_3[i_3].hide_3();
                i_3++;
                n_3 = rand() % 2;
                m_3 = rand() % 2;
                X_3 = x_3[n_3];
                Y_3 = y_3[m_3];
                prob_3[i_3].show_3();
                prob_3[i_3].locate_3(scene_3, X_3, Y_3);
            }
        }
        if (i_3 == 20) {
            printf("\n\n\n");
            printf("======================================================================");
            printf("\n\n\n");
            printf("correct : %d, wrong : %d\n", correct_3, wrong_3);
            printf("\n\n\n");
            printf("======================================================================");
            printf("\n\n\n");
            showMessage(returnresult_3(correct_3));
            prob_3[20].hide_3();
            if (challenge) {
                challenge_show->enter();
                if (correct_3 > 14) {
                    success(3);
                    next->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                        scene_4->enter();
                        init_game_4();
                        return true;
                        });
                }
                else {
                    fail(3);
                    retry->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                        reset_3();
                        prob_3[i_3].hide_3();
                        i_3 = 0;
                        init_game_3();
                        return true;
                        });
                }
            }
            else {
                prac_end->enter();
                select->setScale(0.1);
                restart_button->setScale(0.12);
                restart_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                    reset_3();
                    prob_3[i_3].hide_3();
                    i_3 = 0;
                    init_game_3();
                    return true;
                    });
                select->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                    reset_3();
                    prob_3[i_3].hide_3();
                    i_3 = 0;
                    practice_scene->enter();
                    return true;
                    });
            }
        }
        count_3++;
        return true;
        });

}

///////////////////////////////////////////////////////////////////////////////////////////////// 4번 게임 함수

ScenePtr scene_4; ScenePtr game_4;
ScenePtr scorePage_4 = Scene::create("", "Images4/back_ground.png");
ScenePtr final_4 = Scene::create("", "Images4/back_ground.png");
ObjectPtr yes_play_song_4 = 0;
ObjectPtr no_play_song_4 = 0;

void song_object_4()
{
    yes_play_song_4 = Object::create("Sound/Play_Song_Yes.png", game_4, 1150, 400); yes_play_song_4->setScale(0.5);
    yes_play_song_4->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->play(true);
        yes_play_song_4->hide();
        no_play_song_4->show();
        sound_check = 1;
        return true;
        });
    no_play_song_4 = Object::create("Sound/Play_Song_No.png", game_4, 1150, 400); no_play_song_4->setScale(0.5);
    no_play_song_4->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->stop();
        no_play_song_4->hide();
        yes_play_song_4->show();
        sound_check = 0;
        return true;
        });
}

ObjectPtr cards_4[28];
int emo_4[28] = { 0, }; // 카드 초기화
int arr_4[28] = { 0, }; // 카드 선택 되었는지 확인하는 배열
int unhappy_4 = rand() % 4 + 1; // 불행카드 갯수 (1~4)

int hscore_4[3] = { 10,20,30 }; // 스마일카드 점수 (셋 중 하나)
int hap_4 = hscore_4[rand() % 3];
int uscore_4[3] = { 250, 500, 750 }; // 불행카드 점수 (셋 중 하나)
int unh_4 = uscore_4[rand() % 3];

int totalScore_4 = 0; // 전체 점수
int roundScore_4 = 0; // 라운드 점수

int r_4 = 1;
int rounds_4[10]; //라운드별 점수 배열

ObjectPtr nextbutton_4 = Object::create("Images4/arrow.png", scorePage_4, 520, 255);

std::string indexToImage_4(int index) {
    return "Images4/emot" + std::to_string(emo_4[index]) + ".png";
}

std::string hscImage_4(int hap) {
    if (hap == 10) return "Images4/hscore0.png";
    else if (hap == 20) return "Images4/hscore1.png";
    else return "Images4/hscore2.png";
}

std::string uscImage_4(int unh) {
    if (unh == 250) return "Images4/uscore0.png";
    else if (unh == 500) return "Images4/uscore1.png";
    else return "Images4/uscore2.png";
}

std::string unhImage_4(int unhappy) {
    return "Images4/unh" + std::to_string(unhappy) + ".png";
}

std::string scoreToMes_4(int r, int s) {
    return std::to_string(r) + "라운드 점수는 " + std::to_string(s) + "점 입니다.";
}

void shuffle_4() { // 불행카드 위치 셔플 함수
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 28; i++) {
        emo_4[i] = 0;
    }

    for (int j = 0; j < unhappy_4; j++) {
        if (emo_4[rand() % 28] == 1) --j;
        else emo_4[rand() % 28] = 1;
    }
}

void init_game_4() { // 본 게임 화면
    game_4 = Scene::create("", "Images4/back_ground.png");
    game_4->enter();
    srand((unsigned int)time(NULL));

    auto hsc_4 = Object::create(hscImage_4(hap_4), game_4, 950, 630);
    auto usc_4 = Object::create(uscImage_4(unh_4), game_4, 950, 570);
    auto unhap_4 = Object::create(unhImage_4(unhappy_4), game_4, 950, 510);
    auto next_4 = Object::create("Images4/next.png", game_4, 950, 90);
    next_4->setScale(0.4);
    song_object_4();
    if (sound_check == 1)
    {
        yes_play_song_4->hide();
        no_play_song_4->show();
    }
    else
    {
        yes_play_song_4->show();
        no_play_song_4->hide();
    }


    for (int ind = 0; ind < 28; ++ind) {
        cards_4[ind] = Object::create("Images4/cardback.png", game_4, 100 + (ind % 7) * (100 + 20), 40 + (ind / 7) * (150 + 20));

        cards_4[ind]->setOnMouseCallback([&, ind](auto, auto, auto, auto)->bool {
            cards_4[ind]->setImage(indexToImage_4(ind));

            if (emo_4[ind] == 0) {
                if (arr_4[ind] == 0) {
                    roundScore_4 += hap_4;
                    arr_4[ind] = 1;
                }
            }
            else {
                roundScore_4 -= unh_4;
                showMessage("라운드 종료");
                rounds_4[r_4 - 1] = roundScore_4;
                r_4++;
                totalScore_4 += roundScore_4;

                if (r_4 < 11) {
                    score_init_4();
                }
                else {
                    final_init_4();
                }
            }

            return true;
            });
    }

    next_4->setOnMouseCallback([&](auto, auto, auto, auto)->bool {

        rounds_4[r_4 - 1] = roundScore_4;
        totalScore_4 += roundScore_4;
        r_4++;

        if (r_4 < 11) {
            score_init_4();
        }
        else {
            final_init_4();
        }

        return true;
        });

    shuffle_4();
}

void score_init_4() { // 라운드별 점수 안내 및 다음 라운드로 넘어가기 전 화면
    scorePage_4->enter();

    nextbutton_4->show();

    showMessage(scoreToMes_4(r_4 - 1, rounds_4[r_4 - 2]));

    roundScore_4 = 0;
    hap_4 = hscore_4[rand() % 3];
    unh_4 = uscore_4[rand() % 3];
    unhappy_4 = rand() % 4 + 1;
    for (int i = 0; i < 28; i++) arr_4[i] = 0;


    nextbutton_4->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        init_game_4();
        nextbutton_4->hide();

        return true;
        });
}

std::string finalMes_4(int Total) {
    return "최종 점수는 " + std::to_string(Total) + "점 입니다.";
}

void final_init_4() {  // 최종 점수 화면
    if (challenge) {
        success(4);
        challenge_show->enter();
        next->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            scene_5->enter();
            init_game_5();
            return true;
            });
    }
    else {
        final_4->enter();

        auto restart_4 = Object::create("Images4/restart.png", final_4, 520, 350);
        auto select_4 = Object::create("Images4/select_game.png", final_4, 520, 450);
        restart_4->setScale(0.12);
        select_4->setScale(0.1);

        restart_4->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            roundScore_4 = 0;
            hap_4 = hscore_4[rand() % 3];
            unh_4 = uscore_4[rand() % 3];
            unhappy_4 = rand() % 4 + 1;
            for (int i = 0; i < 28; i++) arr_4[i] = 0;
            r_4 = 1;
            totalScore_4 = 0; // 전체 점수
            roundScore_4 = 0; // 라운드 점수
            for (int i = 0; i < 10; i++) rounds_4[i] = 0;

            init_game_4();

            return true;
            });

        select_4->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            //게임고르는 화면으로 돌아가는 함수
            roundScore_4 = 0;
            hap_4 = hscore_4[rand() % 3];
            unh_4 = uscore_4[rand() % 3];
            unhappy_4 = rand() % 4 + 1;
            for (int i = 0; i < 28; i++) arr_4[i] = 0;
            r_4 = 1;
            totalScore_4 = 0; // 전체 점수
            roundScore_4 = 0; // 라운드 점수
            for (int i = 0; i < 10; i++) rounds_4[i] = 0;
            practice_scene->enter();
            return true;
            });
    }
    printf("\n\n\n");
    printf("======================================================================");
    printf("\n\n\n");
    showMessage(finalMes_4(totalScore_4));
    printf("\n\n\n");
    printf("======================================================================");
    printf("\n\n\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////// 5번 게임 함수

TimerPtr timer1_5, timer2_5, timer_inst_5, timer_show1_5, timer_show2_5;
ScenePtr scene_5;
ObjectPtr start_5 = 0;
ObjectPtr end_5 = 0;
ObjectPtr yes_play_song_5 = 0;
ObjectPtr no_play_song_5 = 0;
ObjectPtr notice_5 = 0;
ObjectPtr i_long_5 = 0;
ObjectPtr i_short_5 = 0;
SoundPtr song_5 = 0;
int arr_20_5[21] = { 0, }, result_your_5[40] = { 0, };
int trial_5 = 20; int count_5 = 0;
int num_right_5 = 0; int time_inc_5 = 0;

void song_object_5()
{
    yes_play_song_5 = Object::create("Sound/Play_Song_Yes.png", scene_5, 1150, 600); yes_play_song_5->setScale(0.5);
    yes_play_song_5->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->play(true);
        yes_play_song_5->hide();
        no_play_song_5->show();
        sound_check = 1;
        return true;
        });
    no_play_song_5 = Object::create("Sound/Play_Song_No.png", scene_5, 1150, 600); no_play_song_5->setScale(0.5);
    no_play_song_5->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        song->stop();
        no_play_song_5->hide();
        yes_play_song_5->show();
        sound_check = 0;
        return true;
        });
}

void reset_5() {
    trial_5 = 20; count_5 = 0;
    printf("\n\n\n");
    printf("======================================================================");
    printf("\n\n\n");

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 40; i++)
    {
        result_your_5[i] = 0;
    }
    srand((unsigned int)time(NULL));
    for (int i_5 = 1; i_5 < 21; i_5++)
    {
        arr_20_5[i_5] = rand() % 2 + 1;
    }
    timer_inst_5 = Timer::create(42.0f);
    timer_inst_5->setOnTimerCallback([&](auto)->bool {
        makeresult_5();
        return true;
        });
    timer_inst_5->start();
    time_inc_5 = -1;
    timer1_5->set(1.95f); timer1_5->start();
    timer_show1_5->set(time_inc_5); timer_show1_5->start();
}

void makeresult_5() {
    printf("\n\n");
    num_right_5 = 0;
    printf("Correct Answer is :\n\n");
    for (int i_5 = 1; i_5 < 21; i_5++)
    {
        printf(" %d", arr_20_5[i_5]);
    }
    printf("\n\nYour Answer is :\n\n");
    for (int i_5 = 0; i_5 < 40; i_5++)
    {
        if ((i_5 % 2) == 0)
        {
            printf(" %d", result_your_5[i_5]);
        }
    }
    printf("\n\nwhether your answer is 'o' or 'x'\n\n\n");
    for (int i_5 = 0; i_5 < 20; i_5++)
    {
        if (arr_20_5[i_5 + 1] == result_your_5[2 * i_5])
        {
            printf(" O");
            num_right_5++;
        }
        else
        {
            printf(" X");
        }
    }
    start_5->show(); 
    char message_in_5[100];
    sprintf(message_in_5, "Your score is %d out of 20 !!!", num_right_5);
    printf("\n\n\n");
    printf("======================================================================");
    printf("\n\n\n");
    showMessage(message_in_5);
    if (challenge) {
        challenge_show->enter();
        if (num_right_5 > 15) {
            success(5);
            hideTimer();
            next->locate(main_scene, 0, 0);
            auto t = Timer::create(2);
            t->start();
            t->setOnTimerCallback([&](auto)->bool {
                song->stop(); song_end->play();
                showMessage("축하합니다 모든 게임을 클리어 하셨습니다!!!");
                com_chall->enter();
                return true;
                });
        }
        else {
            fail(5);
            hideTimer();
            retry->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
                //reset_5();
                scene_5->enter();
                return true;
                });
        }
    }
    else {
        prac_end->enter();
        set_end();
        select->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            //reset_5();
            timer_show1_5->stop();
            hideTimer();
            practice_scene->enter();
            return true;
            });
        restart_button->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            //reset_5();
            scene_5->enter();
            return true;
            });
    }
}

void init_game_5()
{
    song_object_5();
    if (sound_check == 1)
    {
        yes_play_song_5->hide();
        no_play_song_5->show();
    }
    else
    {
        yes_play_song_5->show();
        no_play_song_5->hide();
    }
    i_long_5 = Object::create("Images5/i_long.png", scene_5, 510, 230); i_long_5->setScale(0.5f); i_long_5->hide();        //0 
    i_short_5 = Object::create("Images5/i_short.png", scene_5, 510, 230); i_short_5->setScale(0.5f); i_short_5->hide();    //1

    scene_5->setOnKeyboardCallback([&](ScenePtr scene, KeyCode key, bool pressed)->bool {
        if (count_5 < 40)
        {
            if (key == KeyCode::KEY_LEFT_ARROW)
                result_your_5[count_5] = 1;
            if (key == KeyCode::KEY_RIGHT_ARROW)
                result_your_5[count_5] = 2;
            count_5++;
        }
        return true;
        });

    timer_show1_5 = Timer::create(time_inc_5);
    timer_show1_5->setOnTimerCallback([&](auto)->bool {
        time_inc_5++;
        timer_show2_5->set(1.95f);
        timer_show2_5->start();
        timer_show1_5->set(time_inc_5);
        showTimer(timer_show1_5);
        if (time_inc_5 > 19) {
            timer_show1_5->stop();
        }
        return true;
        });

    timer_show2_5 = Timer::create(1.95f);
    timer_show2_5->setOnTimerCallback([&](auto)->bool {
        timer_show1_5->set(0);
        timer_show1_5->start();
        if (time_inc_5 > 19) {
            timer_show1_5->stop();
        }
        return true;
        });

    timer1_5 = Timer::create(1.95f);
    timer1_5->setOnTimerCallback([&](auto)->bool {
        if (trial_5 > 0) {
            timer2_5->set(1.0f); timer2_5->start();
            timer1_5->set(1.95f);
            timer1_5->start();
        }
        trial_5--;
        i_long_5->hide();
        i_short_5->hide();
        return true;
        });

    timer2_5 = Timer::create(1.0f);
    timer2_5->setOnTimerCallback([&](auto)->bool {
        if (arr_20_5[20 - trial_5] == 1)
        {
            i_long_5->show();
        }
        if (arr_20_5[20 - trial_5] == 2)
        {
            i_short_5->show();
        }
        return true;
        });

    end_5 = Object::create("Images5/end.png", scene_5, 1050, 100); end_5->setScale(1.2f);
    end_5->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        endGame();
        return true;
        });
}

///////////////////////////////////////////////////////////////////////////////////////////////// mian 함수

int main()
{
    srand((unsigned int)time(NULL));
    song = Sound::create("Sound/x-mas.mp3");
    song_end = Sound::create("Sound/x-end.mp3");
    song->play(true);
    song_object();

    //게임 화면, 게임 선택장면 미리 생성
    scene_0 = Scene::create("N_Back Game", "Images0/background.png");
    scene_1 = Scene::create("Hanoi Tower", "Images1/배경.jpg");
    scene_2 = Scene::create("Color_Word", "Images2/background.png");
    scene_3 = Scene::create("word_num", "Images3/배경1.png");
    scene_4 = Scene::create("flip_card", "Images4/back_ground.png");
    scene_5 = Scene::create("Mouth_Len", "Images5/background.png");

    char path_0[50];
    for (int i = 0; i < 12; i++) {
        sprintf(path_0, "Images0/p_blue_base%d.png", i + 1);
        placement_0[i] = Object::create(path_0, scene_0, index_to_x_0(i), index_to_y_0(i));
        placement_0[i]->setScale(0.75);
        placement_0[i]->hide();
    };

    //처음화면 생성
    challenge_button = Object::create("Images/challenge.png", main_scene, 250, 150);
    challenge_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        challenge = true;
        scene_0->enter();
        init_game_0();
        return true;
        });
    practice_button = Object::create("Images/practice.png", main_scene, 750, 150);
    practice_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        challenge = false;
        practice_scene->enter();
        return true;
        });
    off = Object::create("Images/on-off.png", main_scene, 1150, 600);
    off->setScale(0.2f);
    off->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        endGame();
        return true;
        });
    showMessage("초록색 info 버튼으로 연습모드와 챌린지 모드의 차이를 알아보세요 !");
    info = Object::create("Images/info.png", main_scene, 1150, 50);
    mode_info = Object::create("Images/mode_info.png", main_scene, 250, 10);
    mode_info->setScale(0.85f);
    mode_info->hide();
    info->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (info_on == 0) {
            mode_info->show();
            info_on = 1;
        }
        else {
            mode_info->hide();
            info_on = 0;
        }

        return true;
        });
    back = Object::create("Images/left-arrow.png", practice_scene, 50, 650);
    back->setScale(0.12f);
    back->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (intro_on == 1)
        {
            rule_image[intro_on_num]->hide();
            intro_on = 0;
        }
        else
        {
            main_scene->enter();
            if (sound_check == 1)
            {
                yes_play_song->hide();
                no_play_song->show();
            }
            else
            {
                yes_play_song->show();
                no_play_song->hide();
            }
        }
        return true;
        });

    for (int i = 0; i < 6; i++) {
        rule[i] = Object::create("Images/game_rule.png", practice_scene, 150 + 355 * (i % 3), 400 - 260 * (i / 3));
        start[i] = Object::create("Images/game_start.png", practice_scene, 250 + 355 * (i % 3), 400 - 260 * (i / 3));
        rule[i]->setScale(0.8f), start[i]->setScale(0.8f);
        rule[i]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int num = choose_index(object);
            sprintf(introduce_object, "Images/game_rule_%d.png", num);
            rule_image[num] = Object::create(introduce_object, practice_scene, 150, 0); rule_image[num]->setScale(0.27f);
            rule_image[num]->show();
            intro_on = 1;
            intro_on_num = num;
            return true;
            });
        start[i]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int num = choose_index(object);
            if (num == 0)
            {
                scene_0->enter();
                init_game_0();
            }
            if (num == 1)
            {
                scene_1->enter();
                init_game_1();
            }
            if (num == 2)
            {
                scene_2->enter();
                init_game_2();

            }
            if (num == 3)
            {
                scene_3->enter();
                init_game_3();
            }
            if (num == 4)
            {
                init_game_4();
            }
            if (num == 5)
            {
                scene_5->enter();
                init_game_5();
            }
            return true;
            });
    }
    start_5 = Object::create("Images5/start.png", scene_5, 1050, 150); start_5->setScale(1.2f);
    start_5->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        reset_5();
        start_5->hide();
        return true;
        });
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    auto end_chall = Object::create("Images/fin_chall.png", com_chall, 520, 150);
    end_chall->setScale(0.1);
    end_chall->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        endGame();
        return true;
        });
    flag->setScale(0.2);

    startGame(main_scene);
}