# C++ Programming Course and Project

###### tags: `108下` `Industrial Engineering` `project` `Dev C++` `course` 

✏️This note record our project and course material of the NCTU course [Programming](https://timetable.nycu.edu.tw/?r=main/crsoutline&Acy=108&Sem=2&CrsNo=1605&lang=zh-tw) in 2020 spring（108下學期）🏫 

## :robot_face:  About C++ programming project

### Overview : The quick guide of the project

Copyright© of the project is belonged to our Project Member：Chang,Chun-Hsiang、Yu,Yu-Chien、Chiang,Yung-chu. Note that no one shall download, reprint, reproduce, distribute, publicly broadcast, publish or distribute the research content of our project research in any form without written consent.

### Project A : "Tuition Calculator" - How much is your tuition fee, I will help you calculate it well
🏆 Honor : 10/10 grade in the programming course. ![](https://i.imgur.com/BFLWBYV.png)


#### Motivation of the project
At the beginning, we all had a lot of ideas. For example, we thought of a small game that uses psychological tests to match, but in the end, we found that there were many obstacles in implementation. Then I thought that we could design an ordering system to solve the choice problem that we encounter every day, but this is not enough computationally complex. After some twists and turns, the most ideal option was finally decided under the mutual stimulation of creativity: "Tuition Calculator". We chose it for the following reasons:

**1. Solving life problem (live case)**

The fact that National Chiao Tung University is one of the top universities in Taiwan, having a high reputation is obvious that the ones who wish to enter the school is not only Taiwanese students but also those coming from other countries. The struggle the students had to go through at first is related to the university's fee system, especially knowing the right way to pay. International schools could actually estimate their school fee even though it's clear that their fee is double the local students.

That's why we came up with an idea that might be useful and accessed easily. Most importantly, it can be used efficiently for the students to get the information. We would like to ensure that the students are prepared before the school semester starts. This results in the program our group made called Tuition Calculator. It provides an estimation of tuition fees and basically essential costs associated with the school. At last, it covers all the major offered by the school as an undergraduate graduate or in-service student.

**2. Meet the complexity requirements (requires paper and pencil calculation)**
![](https://i.imgur.com/grdzWE0.png)

#### 2. Program description: input, output data, parameter setting and processing methods

- Input data:
1. Account (student number) -> save as int acc
2. Password -> save as int pass (default value is 123456)
3. Number(there will be options to choose from) -> save as int pro, col, id, grd, num, etc.

- Output data:
1. The student's tuition bill (including the amount and total amount of each fee)
2. There are about six multiple-choice questions, with 3 to 9 total options for each question, and each option includes multiple identities or colleges (to distinguish different fees)

- Parameter setting:
All integers, including:
```
int acc = 0, pass = 0, int num
int pro, col, id, grd;
int tuition = 0, MFee = 0; // MFee = Miscellaneous Fees
int TandF = 0, creditF = 0;
// TandF = Tuition and Fees, creditF = Credit Fees
int musicF = 0; // musicF = Individual instruction Fees (only for the
student major in the Intsitute of Music)
int time = 0;
 // for calculating the credit fees for part of the super senior
```
- Processing method:
1. Use the function void printReceipt(int, int, int, int, int, int, int); to output the final tuition report
2. Use the function void printName(int) to list all colleges, departments and options classified according to different tuition fees for students in the university department, research institute, doctoral class and in-service class (in service) respectively (distinguished by if)

Because it is often used in the program, the author writes it as a function, which can avoid many redundant programs. Calling a function multiple times in a program also adds to the savings of the function.

3. 主結構大致為用輸出(cout)提示使用者輸入(cin)約5-6個問題，用巢狀if...else...區隔各種情形，最平凡的狀況大致上就是如以下程序：

**STEP1. 輸入帳號密碼(cin,cout)**
**STEP2. 選擇在學階段(cin,cout)**
->三個選項(if)([1] Undergraduate [2] Graduate [3] In-service) ->每個都有很多分支(if)
**STEP3. 選擇身分(cin,cout)**
->兩個選項(if) ([1] Local Students and Overseas Chinese Students [2] International Students and Chinese (PROC) Students) 
->會影響分支的結果(if)

**STEP4.選擇學院、學系(cin,cout)**

-> 三個選項(if) (For Undergraduate ; 


>
    [1] 
    Colleges of Electrical and Computer Engineering 
    Colleges of Computer Science
    Colleges of Engineering
    Colleges of Photonics
    Colleges Biological Science and Technology
    Departments of Electrophysics
    Departments of Applied Chemistry
    Department Transportation and Logistic Management
    [2] Departments of Applied Mathematics College of Management
    [3] College of Humanities and Social Sciences College of Hakka Studies )

-> 四個選項(if) (For Graduate ;

>
    [1] 
    Colleges of Electrical and Computer Engineering 
    Colleges of Computer Science
    Colleges of Engineering
    Colleges of Photonics
    Colleges of Biological Science and Technology
    College of  Technology Law
    International College of Semiconductor Technology
    College of Artificial Intelligence and Green Energy
    Department Transportation and Logistic Management
    Departments of Electrophysics
    Departments of Applied Chemistry
    International Master of Science Program for Interdisciplinary
    Molecular Science of Materials and Chemical Biology
    International Graduate Degree Program of Sustainable Chemical
    Science and Technology
	[2] 
    Departments of Applied Mathematics
	Institute of Statistics, Institute of Physics
	College of Management
	[3] 
    College of Humanities and Social Sciences
	College of Hakka Studies 
	[4] 
    Degree Program of Global Business Administration)
	
->九個選項(if) (For in-service ;

>
    [1] 
    電機學院在職專班
    資訊學院在職專班
    工學院在職專班
    科技法律學院在職專班
    [2] 
    理學院在職專班
    客家文化學院在職專班
    [3]
    管理科學組在職專班
    運輸物流組在職專班
    經營管理組在職專班
	[4] 工業工程與管理組在職專班
    [5] 資訊管理組在職專班
    [6] 科技管理組在職專班
    [7] 財務金融組在職專班
    [8] 光電學院在職專班
    [9] 高階主管管理碩士學程(EMBA)

->會決定分支的結果(if)

**STEP5.選擇年級三個選項(if)**
>
    三個選項 = [1] First grade [2] Second or above [3] Super senior
    
->每個都有很多分支(if)
(ps.運用#include <stdlib.h>中的system("cls");讓每個步驟或問題結束後的畫面得以清空)

>Sorce code : https://github.com/imyungchu/Programming-course-and-project/blob/main/Project%20A/Poject%20A.cpp

### Project B : Blackjack Game - Can you beat the computer?

#### 1. Motivation of this project

- Something super~ fun 
- And use (1) random numbers, (2) arrays
(It can be said that it is a 1-1 life-and-death fight with the computer, which can be described as the favorite game concept stock of the gods of gamblers after the future technology.)

In the beginning, we all had many ideas. We thought of mini-game, 踩地雷, but in the end, we found that there were many obstacles to implementation. Then we thought that we could design a game called Bingo(賓果), but we felt it sounds boring if we only make the Bingo(賓果) game. We decided to combine Bingo(賓果) with Blackjack(21點). 
After some twists and turns, finally decided the ideal option under the mutual agitation of creativity: "21 Point Gambling”. We chose it for the following reasons:

1. Something fun and uses (1) random numbers, (2) arrays
Poker games can be applied to the functions of arrays and random numbers in the program. When you need to store multiple cards at the same time, you need to use the array to store, and when you draw cards, you need to use the characteristics of random numbers, plus playing cards. The universality of the game makes its rules familiar to the public, and it is easier to get started in a short time.

2. "Playfulness"
Considering that it seems a little boring if there is only pure blackjack, we have thought about trying to combine bingo and blackjack, but it seems that the rules design and gameplay still cannot meet the requirements of "fun", and it is difficult to be perfect, so we Think other ways instead, taking into account the human innate love of the game and near-mad fascination. The so-called small gambling can make you happy, and big gambling can prosper your country and build a business. Human beings are naturally excited about money games. As long as you go to the gambling table, you will feel that your heartbeat will speed up and your blood will speed up. Therefore, we combine the wagering system with blackjack, adding a little stimulation to entertainment and leisure, in order to meet the requirements of "fun".

Knowing loving to win and hating to lose is one of the basic human trait. We have added the factor of winning and losing the game into our program. The player will “win” the game when they have reached the condition we have set into the game, that is the player will win the game when their money reach 5000. On the other hand the condition for losing is also added into the game. The player will lose the game when their money reached 0. The end will end immediately when the player reach the condition needed to win or lose. Another special condition to win has also been added to the game where the player will immediately win the game when his card reaches 5 and his points have not exceed 21.

#### 2.Program description: input, output data, parameter setting and processing methods

- input data
    擇賠率大小  →int mag
    1.	輸入賭注金額  →int pri
    2.	選擇是否要再抽一張牌  →char answer

- 輸出資料
    1.	在每一次玩家抽取下一張牌後，印出目前玩家的所有手牌和電腦所取得的第一張牌
    2.	在每回合結束後印出結果，包括
            i.	玩家和電腦的所有手牌
            ii.	目前所擁有的資金
            iii.	本輪結果，以玩家為主體，分為獲勝、失敗、平手等情況
    3.	在最終當資金大於等於5000或小於等於0時，印出成功或失敗
- Parameter setting
- Integer
    1.	usermoney → 玩家資金
    2.	i, j → 作為陣列的index
    3.	total → 玩家的牌值總和
    4.	total_2 → 電腦的牌值總和
    5.	bothbust → 判斷是否有兩邊同時爆牌的狀況，預設為0
    6.	mag → 賠率
    7.	pri → 本輪所下注的金額

- 布林值
    1.	fiveCard → 判斷是否為特殊情況，預設為False
- 陣列
    1.	player → 玩家手牌
    2.	computer → 電腦手牌
- 函數
    1.	draw() → 使用rand()隨機產生1~13之間的數字來模擬抽牌
    2.	oneMoreOrNot → 使電腦判斷是否要抽下一張卡
    3.	sum → 計算牌值總和
    4.	printcards → 印出目前手牌，包含能判斷要印出J Q K 而非 11 12 13


- 處理方法
玩家開始時預設資金為1000元，並可在每一輪開始前選擇賠率大小，分別為1:1、1:2、1:5，接著可選擇下注金額。玩家獲勝條件為資金成長至5000元。每一次抽牌後檢查玩家手牌值和電腦手牌值是否有超過21點，使用if-else條件句，若有一方或雙方同時爆牌則直接跳出迴圈，進入結果頁面。計算時使用sum()輔助計算牌值，J, Q, K牌值皆須計算為10，並將目前玩家和電腦總和儲存。玩家是否繼續抽牌由玩家自行決定，而電腦是否抽下一張牌則由oneMoreOrNot()決定，此函數計算電腦在十三張牌中有幾張是符合條件(抽到後不會爆牌)，將此牌數除以13作為不會爆牌的機率，若此機率大於0.416則抽下一張牌，反之則否。當玩家不再要牌後，使用if-else條件句判斷輸贏或平手，最後計算所得賭金 = 投入賭金 * 賠率。接著重複幾輪直到玩家資金達到5000或輸光為止。
- 特殊情況：
(i) 玩家取得五張牌後尚未爆牌(超過21點)，則直接獲勝，由布林值fiveCard判斷。
(ii) 若雙方同時爆牌則為平手，由變數bothBust判斷。

>Sorce code : https://github.com/imyungchu/Programming-course-and-project/blob/main/Project%20B/project%20B(3.2).cpp

## :notebook_with_decorative_cover: The Homeworks and Materials of the course

Copyright© The homeworks and teaching materials is provided by the professor of the course, [Nick Wang](https://arg-nctu.github.io) , and the answers in some code blocks is added by me.

| Homework : Grade   |  link              | 
| ----------------- |:----------------------- |
| Lab1 : 10/10   | [:link:][1]  |
| Lab2 : 10/10    | [:link:][2]  |
| Lab3 : 10/10       | [:link:][3]    | 
| Lab4 : 14/15        | [:link:][4]     |
| Lab5 : 10/10     | [:link:][5]     |
| Lab6 : 9/10 | [:link:][6]|
    
    


[1]: https://github.com/imyungchu/Programming-course-and-project/tree/main/HW/HW1

[2]: https://github.com/imyungchu/Programming-course-and-project/tree/main/HW/HW2

[3]: https://github.com/imyungchu/Programming-course-and-project/tree/main/HW/HW3

[4]: https://github.com/imyungchu/Programming-course-and-project/tree/main/HW/HW4

[5]: https://github.com/imyungchu/Programming-course-and-project/tree/main/HW/HW5

[6]:https://github.com/imyungchu/Programming-course-and-project/tree/main/HW/HW6







- Watch MORE of my projects ➜ [My GitHub repositories](https://github.com/imyungchu?tab=repositories)

