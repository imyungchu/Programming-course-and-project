// Function Name:    Menu & Shopping
// Version: 0.7
// Function Describe: 
//   (1).print menu and the price policy. 
//   (2) shopping cart : use do...while loop and [n] to add / remove items in the cart.    
// Create by:   Paul Lin     CDate: 2020-04-01 
// Modified by:              MDate: 

#include <iostream>
#include <iomanip>   // include object: setw() format output 
#include <string>    // include object: system("CLS") clean screen  

using namespace std;

int main() {

    //Variables declaration 
    int NoA = 0;  //Number of apple in the shopping cart 
    int NoB = 0;  //Number of banana in the shopping cart 
    int op = 0;   //[n] the operation code given by user in every iteration 

    do { // do... while loop 
    	
    	system("CLS");  //Clean screen at the begining in every iteration  
    	
	    cout << "********************************" << endl;
	    cout << "*  apple    $10     [1]+" << setw(3) << NoA << "-[2]*"<< endl;
	    cout << "*  banana    $7     [3]+" << setw(3) << NoB << "-[4]*"<< endl;
	    cout << "********************************"<< endl;
	    cout << "Enter op code(-1 to checkout):";
	    cin >> op;
	
	    //update NoA and NoB, !!! have known bugs need to modified !!! 
	    if (op == 1) 
	        NoA++;
	    if (op == 2)
	        NoA--;
	    if (op == 3)
	        NoB++;
	    if (op == 4)
	        NoB--;	
    	
    	
	} while (op != -1); // condition is not checkout 
	

    //checkout and show how much to pay. 


	
	return 0;
}


