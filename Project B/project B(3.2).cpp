// Function Name : 21 point gambling !!!!  
// Version: 2.0
// Function Describe: Exciting & Funny :D
// Create by: Chang, Chun-Hsiang       CDate: 2020/06/10
// Modified by:  Chiang,Yung-chu       MDate: 2020/06/15
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int draw() { //生成1~13的亂數(撲克牌抽牌) 
	return 1 + rand() % 13;
}
bool oneMoreOrNot(int);
int sum(int[], int);
void printCards(int [], int);

int main() {
    char answer;
    int userMoney = 1000;
    cout << "Blackjack (21 Points)!" << endl;
    do {
        int i = 0, j = 0, total = 0, total_2 = 0, cnt5 = 0;
        int player[10] = {}, computer[10] = {}; // array for player's and computer's hand cards
        int bothBust = 0; 
		bool fiveCard = false; // for special situation five cards
        srand(time(NULL)); // provide seed for rand()
		
		int mag;				//倍率 
		int pri;				//本金 
		
		cout<<"Which magnification do you want to choose:"<<endl;	 
		cout<<"[1] 1:1 ; [2] 1:2 ; [3] 1:5"<<endl;					 //問使用者要玩的倍率
		cin>>mag;
		if(mag==3){		
			mag=5;													//只有在使用者選3的時候需要把倍率改成5 
		}
		system("cls"); // clean the screen
		do {
			cout << "Your money: $" << userMoney << endl;
			cout<<"How much money do you want to gamble?"<<endl;				//問使用者要賭多少錢	 
			cin>>pri;
		} while (pri > userMoney || pri <= 0);
		userMoney -= pri;
		system("cls");
        cout<<"Enter y for a card :";
        cin>>answer;
        cout<<endl;
		do {
			 // for computer to draw a card or not
            computer[j]=draw(); // save computer's card in the array
            j++;
            total_2+=sum(computer, j); //calculate the computer's current sum
		}while(oneMoreOrNot(total_2));
        if(answer=='y') {
            do {
				player[i]=draw(); // save the card in the player's array
                i++; cnt5++;
                total+=sum(player, i); //calculate the current amount of the player
                if(cnt5 == 5 && total <= 21) { // the special case of holding 5 cards and still not bust
					fiveCard = true;
					break;
				}
                cout<<"Your hand cards: ";
                printCards(player, i); // print current hand cards
                cout<<"Computer's first hand card: ";
                if (computer[0] > 10) { // print computer's first card
                	if (computer[0] == 11) { 
                		cout << "J" << endl;
					} else if (computer[0] == 12) {
						cout << "Q" << endl;
					} else {
						cout << "K" << endl;
					}
				} else {
					cout << computer[0] << endl;
				}
				
                if(total>21 || total_2>21) { // determine if anyone bust
                    if(total>21) {
						cout<<"You Bust!"<<endl;
						bothBust++;
					}
                    if(total_2>21) {
                    	cout<<"Computer Bust!"<<endl;
                    	bothBust++;
                    } 
                    break;
                }

                cout<<endl<<endl<<"Another card?(y/n) "; // ask if the player want another card
                cin>>answer;
                cout<<endl;
                if (answer == 'n' || answer == 'N') break; // if the answer is no, break
                else system("cls"); // clean the screen
            } while(true);
        }
		system("cls");
        cout<<"--------------------------------------------"<<endl;
        cout<<"Result: "<<endl; // print the result
		cout<<"Your hand cards: ";
		printCards(player, i);
		cout<<endl<<"Computer's hand cards: ";
		printCards(computer, j);
		//determine different situation of winning and loosing
        if(total>total_2 && total<=21 || total_2>21 || fiveCard){
			cout<<endl<<"You Win!"<<endl;
			userMoney +=  pri + (mag * pri);
		} 
        else if(total<total_2 && total_2<=21 || total>21){
			cout<<endl<<"You lose!"<<endl;
	    	userMoney += pri - (mag * pri);
		}
        else if(total == total_2 || bothBust == 2) {
            cout<<endl<<"Tie!"<<endl;
            userMoney += pri;
        }
        cout << "Your money: $" << userMoney << endl; 
        if (userMoney <= 0) { 
         cout << "You're a loser :)))" << endl; 
         break; 
  		} 
        if (userMoney >= 5000) { 
         cout << "You're the KING!!!" << endl; 
         break; 
  		}
    } while(true);
    
    return 0;
}
bool oneMoreOrNot(int ctotal) { //for computer to decide to draw antother card or not 
	int diff = 21-ctotal; 
	double cnt = 0;
	if(diff>=10) cnt += 10-diff+3; // for J Q K all has the value of 10
	for(int i=1;i<=diff;i++) // calaulate the number of cards the computer can have and do not bust 
		cnt++;
	if(cnt/(double)13>0.416) return true; // We set the bottom line as 0.416. If the possibilty is greater, then draw another card. 
	else return false;
}
int sum(int c[], int index) { // for calculating the value of J Q K as 10 
	if(c[index-1]>10) return 10;
	else return c[index-1];
}
void printCards(int c[], int n) { // print all card on the screen
	for(int i=0;i<n;i++) {
		switch(c[i]) {
			case 11:
				cout<<"J"<<" ";
				break;
			case 12:
				cout<<"Q"<<" ";
				break;
			case 13:
				cout<<"K"<<" ";
				break;
			default:
				cout<<c[i]<<" ";
		}
	}
	cout<<endl;
}
