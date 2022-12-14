// Function Name: Guess Number 
// Version: 0.2 
// Function Describe: 
//   (1).use function to help generate a number without digit repetition. 
//   (2).use function to count the number of A and B.     
// Create by:   Xiao-Hwa          CDate: 2020-05-13 
// Modified by:  Yung-chu,chiang  MDate: 2020-05-15

#include <iostream>
#include <cstdlib>
#include <ctime> //產生隨機亂數 

using namespace std;

bool check4Repeat(int , int);

int check4A(int , int , int);

int check4B(int , int , int); 
  
 

int main() {
  	srand (time(0));//產生隨機亂數
  	int Target = 0 ; // the number for guessing.
  	//提示使用者輸入3、4、5的數字，來決定要用幾位數來猜
  	int dig ;
  	cout << "Please input 3,4 or 5 to decided the digits of the number:" ;
  	cin >> dig ;
  		
	if ( dig == 4){
  			do {
     		//if digit repetition occurs(true), re-generate a number 
     		Target = (rand() % 9876 + 123) ;  //Why 9876 and 123 ???? 
     		//要產生 A~B 間的亂數的話，就用(rand()%(B-A+1))+A;so the program above can produce 123~9998 at random
     		//0000~0123和9876~9999都是會有重複數字的Target所以可以藉由這樣設定扣除一些不必要的數字 
  			}
  			while (check4Repeat(Target,dig)) ; 
  			cout << "I had a 4 digit positive interger without digit repetition (ex: 9876, 0123), Can you guess this number ?" << endl; 
  			//cout << Target << endl;
  			}
  		
  	if ( dig == 3){
  			do { 
     		Target = (rand() % 975 + 12) ;
			  //產生012~987的亂數 省略0~12 and 987~999 都會有重複  
  			}
  			while (check4Repeat(Target,dig)) ;
			cout << "I had a 3 digit positive interger without digit repetition (ex: 987, 012), Can you guess this number ?" << endl; 
  			//cout << Target << endl;
  		}
		
  	if ( dig == 5){
  			do { 
     		Target = (rand() % 97531 + 1234) ;
			//產生01234~98765的亂數 省略0~1234 and 98765~99999 都會有重複  
  			}
  			while (check4Repeat(Target,dig)) ; 
  			cout << "I had a 5 digit positive interger without digit repetition (ex: 98765, 01234), Can you guess this number ?" << endl; 
  			//cout << Target << endl;
			}  
int Guess = -1; // the number user guessed. 
  
  	while(Guess != Target) {
     	cout << "Make a guess :"; 
     	cin >> Guess; 
  		 	if (Guess == Target) 
	    		cout << "Yes, " << Target << " is the number!"<< endl; 
     		else 
	    		cout << check4A(Target, Guess,dig) << "A" << check4B(Target, Guess,dig) << "B" << endl; 
	 			} 
  			cout << Target; 
	return 1; 
	
}

bool check4Repeat(int Target,int dig){
if (dig == 4){
	int a = Target % 10 ;//個位數 
	int b = ((Target / 10) %10 );//十位數 
	int c = ((Target / 100) %10 );//百位數
	int d = Target/1000 ;//千位數
	if ( a==b || b==c || c==d || c==a || b==d || a==d) 
		return true ; 
	else
		return false ;
}
if (dig ==3 ){
	int a = Target % 10 ;//個位數 
	int b = ((Target / 10) %10 );//十位數 
	int c = (Target / 100) ;//百位數
	if ( a==b || b==c || c==a ) 
		return true ; 
	else
		return false ;
}	
if (dig == 5){
	int a = Target % 10 ;//個位數 
	int b = ((Target / 10) %10 );//十位數 
	int c = ((Target / 100) %10 );//百位數
	int d = ((Target / 1000) %10 );//千位數
	int e = Target/10000;//萬位數 
	if ( a==b || b==c || c==d || d==e || c==a || b==d || a==d || a==e || b==e || c==e ) 
		return true ; 
	else
		return false ;
} 
}

int check4A(int Target, int Guess,int dig){
	int j ;
	int A = 0 ;
		for ( j = 1 ; j <= dig ; j ++ ){
			int x = Target % 10 ;
			int y = Guess % 10 ;
			if ( x == y)
			A++;
			Target = Target/10 ;
			Guess = Guess/10 ;
		}
	return A;
	}



int check4B(int Target, int Guess,int dig){

	if(dig==4){
	//Target partition
	int a = Target % 10 ;//個位數 
 	int b = ((Target / 10) %10 );//十位數 
 	int c = ((Target / 100) %10 );//百位數
 	int d = Target/1000 ;//千位數
 	//Guess partition
 	int e = Guess % 10 ;//個位數 
 	int f = ((Guess / 10) %10 );//十位數 
 	int g = ((Guess / 100) %10 );//百位數
 	int h = Guess/1000 ;//千位數
 	//judge B
 	int B = 0 ;
 	if (a==f)
 	B++;
 	if (a==g)
 	B++;
 	if (a==h)
 	B++;
 	if (b==e)
 	B++;
 	if (b==g)
 	B++;
 	if (b==h)
 	B++;
 	if (c==f)
 	B++;
 	if (c==e)
 	B++;
 	if (c==h)
 	B++;
 	if (d==f)
 	B++;
 	if (d==e)
 	B++;
 	if (d==g)
 	B++;
	return B;
	}
	if(dig==3){
	//Target partition
	int a = Target % 10 ;//個位數 
 	int b = ((Target / 10) %10 );//十位數 
 	int c = (Target / 100 );//百位數
 	//Guess partition
 	int e = Guess % 10 ;//個位數 
 	int f = ((Guess / 10) %10 );//十位數 
 	int g = (Guess / 100) ;//百位數
 	//judge B
 	int B = 0 ;
 	if (a==f)
 	B++;
 	if (a==g)
 	B++;
 	if (b==e)
 	B++;
 	if (b==g)
 	B++;
 	if (c==f)
 	B++;
 	if (c==e)
 	B++;
	return B;
	}
	if(dig==5){
	//Target partition
	int a = Target % 10 ;//個位數 
 	int b = ((Target / 10) %10 );//十位數 
 	int c = ((Target / 100) %10 );//百位數
 	int d =((Target / 1000) %10 );//千位數
 	int d2 = Target/10000 ;//萬位數
 	//Guess partition
 	int e = Guess % 10 ;//個位數 
 	int f = ((Guess / 10) %10 );//十位數 
 	int g = ((Guess / 100) %10 );//百位數
 	int h =((Guess / 1000) %10 );//千位數
 	int h2 = Guess/10000 ;//萬位數
 	//judge B
 	int B = 0 ;
 	if (a==f)
 	B++;
 	if (a==g)
 	B++;
 	if (a==h)
 	B++;
 	if (a==h2)
 	B++;
 	if (b==e)
 	B++;
 	if (b==g)
 	B++;
 	if (b==h)
 	B++;
 	if (b==h2)
 	B++;
 	if (c==f)
 	B++;
 	if (c==e)
 	B++;
 	if (c==h)
 	B++;
 	if (c==h2)
 	B++;
 	if (d==f)
 	B++;
 	if (d==e)
 	B++;
 	if (d==g)
 	B++;
 	if (d==h2)
 	B++;
 	if (h2==f)
 	B++;
 	if (h2==e)
 	B++;
 	if (h2==g)
 	B++;
 	if (h2==h)
 	B++;
 	
	return B;
	}
	
}
