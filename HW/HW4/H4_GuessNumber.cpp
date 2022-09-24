// Function Name: Guess Number 
// Version: 0.1 
// Function Describe: 
//   (1).use function to help generate a number without digit repetition. 
//   (2).use function to count the number of A and B.     
// Create by:   Xiao-Hwa     CDate: 2020-05-13 
// Modified by:              MDate: 

#include <iostream>
#include <cstdlib>

using namespace std;

bool check4Repeat(int Target);
int check4A(int Target, int Guess);
int check4B(int Target, int Guess); 
 
int main() {
  
  int Target = 0; // the number for guessing. 
  
  do {
     //if digit repetition occurs(true), re-generate a number 
     Target = (rand() % 9876 + 123);  //Why 9876 and 123 ???? 
  }
  while (check4Repeat(Target)); 
  
  cout << "I had a 4 digit positive interger without digit repetition (ex: 9876, 0123), Can you guess this number ?" << endl; 
  //cout << Target << endl; 
  
  int Guess = -1; // the number user guessed. 
  
  while(Guess != Target) {
  
     cout << "Make a guess :"; 
     cin >> Guess; 
  
     if (Guess == Target) 
	    cout << "Yes, " << Target << " is the number!"<< endl; 
     else {
	    cout << check4A(Target, Guess) << "A" << check4B(Target, Guess) << "B" << endl; 
	 } 
	 
  } 
  
  cout << Target; 

  return 1; 
}



