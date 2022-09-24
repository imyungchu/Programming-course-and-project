// Function Name:    Menu & Shopping
// Version: 0.8
// Function Describe: 
//   (1).print menu and the price policy. 
//   (2) shopping cart : use do...while loop and [n] to add / remove items in the cart.    
// Create by:   Paul Lin     CDate: 2020-04-01 
// Modified by:  江詠筑      MDate: 2020-04-05 

#include <iostream>
#include <iomanip>   // include object: setw() format output 
#include <string>    // include object: system("CLS") clean screen  

using namespace std;

int main() {

    //Variables declaration 
    int NoA = 0;  //Number of apple in the shopping cart 
    int NoB = 0;  //Number of banana in the shopping cart
	int NoO = 0; 
    int op = 0;   //[n] the operation code given by user in every iteration 

    do { // do... while loop 
    	
    	system("CLS");  //Clean screen at the begining in every iteration  
    	
	    cout << "********************************" << endl;
	    cout << "*  apple    $10     [1]+" << setw(3) << NoA << "-[2]*"<< endl;
	    cout << "*  banana    $7     [3]+" << setw(3) << NoB << "-[4]*"<< endl;
	    cout << "*  orange    $8     [5]+" << setw(3) << NoO << "-[6]*"<< endl;
	    cout << "********************************"<< endl;
	    cout << "Big SALE!! 3 apples cost only $25"<< endl;
	    cout << "Enter op code(-1 to checkout):";
	    cin >> op;
	
	    //update NoA and NoB, bugs have modified by 江詠筑 
	    // Avoid the situations causing number <0 by adding some condition in if loop
		if (op == 1) 
	        NoA++;
	    if (op == 2 && NoA != 0 ) //避免出現NoA <0的狀況:加入&&(且) NoA != 0使其只有在值不為零才能運作 
	        NoA--;
	    if (op == 3)
	        NoB++;
	    if (op == 4 && NoB != 0 )//避免出現NoB <0的狀況:加入&&(且) NoB != 0使其只有在值不為零才能運作
	        NoB--;
		if (op == 5)
	        NoO++;
	    if (op == 6 && NoO != 0 )//避免出現NoO <0的狀況:加入&&(且) NoO != 0使其只有在值不為零才能運作
	        NoO--;	
		
		
    	
    	
	} while (op != -1); // condition is not checkout 
	

    //checkout and show how much to pay. 
	
		if ( NoA >= 3) //只特價一組，所以NoA>=3時可以直接用$25代表其中三個 Apple的價錢 
		cout << "The money you need to pay is : $" << 25 + (NoA-3)*10 + NoB*7 + NoO*8 << endl ;
		else //NoA <3 正常計算即可 
		cout << "The money you need to pay is : $" << NoA*10 + NoB*7 + NoO*8 << endl ;
	

	
	return 0;
}


