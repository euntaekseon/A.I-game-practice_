# A.I game :computer:
###### (어플 '다마자'를 참고하여 추가 기능을 구현한 게임입니다.)   
본 게임은 AI 면접에 사용되는 6개의 게임들을 한 곳에 모아 구성한 게임입니다.  
AI면접 전에 미리 연습해볼 수 있도록 제작했습니다.

<br/>

## 초기화면

게임은 크게 챌린지모드와 연습모드로 구분됩니다.  
플레이어는 연습모드로 6개의 게임들을 연습해보고, 챌린지모드에 도전할 수 있습니다.  
음악은 스피커 버튼을 이용해 끄거나 킬 수 있고, 파란색 전원 버튼을 누르면 게임은 종료됩니다.  
초록색 INFO 버튼을 연습모드와 챌린지모드에 대한 설명을 볼 수 있습니다.

![스크린샷(181)](https://user-images.githubusercontent.com/49235600/143726388-a6a7b7c3-324b-4c39-b61e-be72c6d48c95.png)

  
    

### INFO 버튼

초록색 INFO 버튼을 클릭했을 때의 화면입니다.  
연습모드와 챌린지모드의 차이점과 주의사항에 대해 알 수 있습니다.  
챌린지모드로 플레이했을 때의 성공기준에 대한 내용도 담고 있습니다.  

![스크린샷(209)](https://user-images.githubusercontent.com/49235600/143823678-4d5a2482-740c-43a9-aa9c-b777bcddc63a.png)
  
    
  
  

## 1. 연습 모드

연습모드를 클릭하면 A.I game에서 제공하는 6개의 게임들을 볼 수 있습니다.  

![스크린샷(183)](https://user-images.githubusercontent.com/49235600/143726960-8032fb0d-13b4-4dad-ab62-4617788a4e88.png)

규칙을 클릭하면 각 게임들의 실행 규칙이 나오고, 게임 시작을 클릭하면 게임이 실행됩니다.  

![스크린샷(185)](https://user-images.githubusercontent.com/49235600/143727078-0b94ff33-ed9b-49d3-94a3-81b1c2bf284b.png)

플레이한 게임이 종료가 되면 최종 점수를 볼 수 있고, 다른 게임 하기 버튼과 다시하기 버튼도 볼 수 있습니다.  

다른 게임 하기를 클릭하면 연습 모드 초기 화면으로 넘어가고, 다시하기 버튼을 클릭하면 해당 게임을 다시 플레이할 수 있습니다. 

![스크린샷(188)](https://user-images.githubusercontent.com/49235600/143727547-4c5a41fb-9c69-48e0-9f53-c4670605e669.png)


---
### GAME 1: 도형 위치 기억하기 :back:

> 도형 위치 기억하기 게임의 실행화면입니다.  2back과 3back 두 가지 버전 중에서 선택할 수 있고, END를 누르면 게임이 종료됩니다.  
> 반복적으로 보여주는 사각형 배열에서 제시된 색깔의 도형의 위치가 N번째 전의 도형 위치와 동일한지 판단하는 게임입니다.  
> 같다면 왼쪽 방향키를 누르고, 다르다면 오른쪽 방향키를 누릅니다.  

![스크린샷(212)](https://user-images.githubusercontent.com/49235600/143826844-becec30f-912a-4536-a090-48825e4e4eae.png)


### GAME 2: 하노이탑 쌓기 :link:

> 하노이탑 쌓기 게임의 실행화면입니다.   EASY와 HARD 두 가지 모드 중에서 선택하여 실행할 수 있는데, 모드에 따라 원반을 움직일 수 있는 횟수가 제한되어 있습니다.  
> EASY모드는 4개의 원반을 18안에 옮겨야 하고, HARD모드는 5개의 원반을 37번 안에 옮겨야 합니다.  
> 게임 실행 중 RESTART를 누르면 하노이탑 쌓기 게임을 다시 시작할 수 있습니다.  
> 계획 능력을 기를 수 있는 게임입니다.  

![스크린샷(214)](https://user-images.githubusercontent.com/49235600/143827121-ecf70eee-ec36-4875-86f2-1b9dad85e2b2.png)
![스크린샷(219)](https://user-images.githubusercontent.com/49235600/143827702-01fa39af-d0b5-4f53-9b0e-5f536651aa4e.png)

### GAME 3: 색-단어 일치판단 :art:

> 색-단어 일치판단 게임의 실행화면입니다.  우측의 글씨 색과 좌측의 글씨 의미가 일치하는지 판단하는 게임입니다.  
> 일치한다면 왼쪽 방향키를, 일치하지 않다면 오른쪽 방향키를 누릅니다.  상황 판단 능력을 향상시킬 수 있는 게임입니다.  

![스크린샷(197)](https://user-images.githubusercontent.com/49235600/143728740-5d890e75-0b19-424c-baf5-cd8c6ee2d924.png)

### GAME 4: 글자-숫자 분류하기 :mag:

> 글자-숫자 분류하기 게임의 실행화면입니다.  
> 주어진 글자와 숫자가 제시된 기준에 부합하는지 판단하는 게임으로, 숫자가 짝수/홀수인지와 글자가 모음/자음인지에 따라 조건이 나뉩니다.  
> 모든 조건에 부합한다면 왼쪽 방향키를, 부합하지 않다면 오른쪽 방향키를 누릅니다.  이해력과 순발력을 기를 수 있는 게임입니다.

![스크린샷(196)](https://user-images.githubusercontent.com/49235600/143729664-83bfb91c-7c2a-493c-b324-23fea0eb2ae0.png)


### GAME 5: 카드 뒤집기 :black_joker:

> 카드 뒤집기 게임의 실행화면입니다.  
> 플레이어는 보상/손실 및 확률 정보를 활용하여 카드를 계속해서 뒤집을 것인지, 또는 다음 라운드로 넘어갈 것인지 선택할 수 있습니다.  
> 총 10개의 라운드로 구성되어 있으며, 전체 라운드에서 얻은 점수를 누적하여 최대 이익을 얻어야 하는 게임입니다.  
> 한 라운드가 끝나면 해당 라운드에서 획득한 점수를 보여줍니다.  상황 판단 능력을 기를 수 있는 게임입니다.  

![스크린샷(201)](https://user-images.githubusercontent.com/49235600/143729663-ba2bd4f7-bcb9-4cb0-bfe8-ccda72895bc2.png)
![스크린샷(204)](https://user-images.githubusercontent.com/49235600/143729822-5df41159-b489-4090-8945-c352bd2d4c70.png)


### GAME 6: 입길이 맞히기 :neutral_face:

> 입길이 맞히기 게임의 실행화면입니다. 화면에 두 가지 길이의 입이 나타났다 사라집니다.  
> 이 때 그 미세한 길이 차이를 구분하여 2초 안에 입길이가 길다면 왼쪽을, 짧다면 오른쪽 방향키를 누르는 게임입니다.  변별력을 기를 수 있는 게임입니다.  

![스크린샷(199)](https://user-images.githubusercontent.com/49235600/143729662-4961bc66-5cbb-4b79-9b30-bf606e2154a6.png)



---

## 2. 챌린지 모드

챌린지모드를 클릭하면 첫 번째 게임인 도형 위치 기억하기 게임부터 플레이됩니다.  한 게임에서 일정한 기준치를 달성하면, 챌린지에 성공하여 자동으로 다음 게임 화면으로 이동합니다.

이 때 성공하여 다음 게임으로 넘어가기 전, 아래 화면에 보이는 노란색 캐릭터의 위치가 앞으로 조금씩 전진하여 챌린지 성공률을 보여줍니다.  

만약 게임을 성공하지 못 했더라도 다시하기 버튼을 클릭하여 그 게임 챌린지에 재도전할 수 있습니다. 

챌린지모드의 클리어 기준은 다음과 같습니다.

- 도형 위치 기억하기(N back) 게임: 13개 이상 성공
- 하노이탑 쌓기 게임: 제한된 횟수 안에 원반을 다 옮겼을 경우 성공(EASY-18번/HARD-37번)
- 카드 뒤집기 게임: 기준X
- 그 외 색-단어 일치판단, 글자-숫자 분류하기, 입길이 맞추기: 15개 이상 성공

![스크린샷(206)](https://user-images.githubusercontent.com/49235600/143730129-1d06f5f9-690d-48b2-bce9-7e56773cc1a3.png)
![image](https://user-images.githubusercontent.com/83305042/143971031-dcd71bd1-b97e-4a49-923c-dd764e0402bd.png)
> 챌린지 완료 화면


---

## Our Team
- 김유선(20175465)
- 김주환(20202373)
- 김지우(20171096)
- 선은택(20180330)
