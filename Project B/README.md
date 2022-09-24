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
