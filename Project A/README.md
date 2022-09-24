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
