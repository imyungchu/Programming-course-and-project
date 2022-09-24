/*
	Name: Tuition Calcualtor 
	Author: Chang, Chun-Hsiang
	Date: 28/04/20 19:51
	Description: Calculating the total amount of tuition and fees in different conditions
	Modify: 余侑謙 
	Modified time: 29/04/20, 05/05/20, 09/05/20 
*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

// function for printing name of colleges/departments/institutes in different selected programs
void printName(int); 
// fuction for printing the result
void printReceipt (int, int, int, int, int, int, int);

int main() {
	// Access page, capable for recognizing wrong password
	int acc = 0, pass = 0;
	cout<<setw(10)<<""<<"Tuition and Crdeit Fees System"<<endl<<endl;
	do { 
		cout<<"Account Name (Student ID): ";
		cin>>acc;
		cout<<"Password (123456): "; 
		cin>>pass;
		if (pass != 123456) // default: 123456
			cout<<"Wrong account name or password!"<<endl<<"Please reenter!"<<endl;
	} while (pass != 123456); // Will repeat until the users enter the right password
	system("cls"); // Clean the screen
	
	// Declare variables for different purposes
	int pro, col, id, grd;
	int tuition = 0, MFee = 0; // MFee = Miscellaneous Fees
	int TandF = 0, creditF = 0; // TandF = Tuition and Fees, creditF = Credit Fees
	int musicF = 0; // musicF = Individual instruction Fees (only for the student major in the Intsitute of Music)
	int time = 0; // for calculating the credit fees for part of the super senior
	
	// Prompt the users to select their programs, save the result in variable "pro"
	cout<<"Please select your programs"<<endl<<"[1] Undergraduate  [2] Graduate [3] In-service"<<endl;
	cout<<"ANS: ";
	cin>>pro;
	system("cls");
	
	// Prompt the users to select their identities, save the result in variable "id"
	cout<<"Please select your identity"<<endl;
	cout<<"[1] Local Sutdents and Overseas Chinese Students"<<endl;
	cout<<"[2] International Students and Chinese (PROC) Students"<<endl;
	cout<<"ANS: ";
	cin>>id;
	system("cls");
	
	if (pro == 1) {  // for the users in the undergraduate programs
		// Prompt the users to select their colleges or departments, save the result in variable "col"
		cout<<"Please select your college/department"<<endl; 
		printName(pro);
		cout<<"ANS: ";
		cin>>col;
		system("cls");
		
		// Prompt the users to select their grades, save the result in variable "grd"
		cout<<"Please select your grade"<<endl;
		cout<<"[1] First grade"<<endl<<"[2] Second or above"<<endl<<"[3] Super senior"<<endl;
		cout<<"ANS: ";
		cin>>grd;
		system("cls");
		
		if (grd == 3) { // Special case for super senior 
			cout<<"Please enter your weekly class hours: ";
			cin>>time;
			if(time <= 9) { // for super seniors whose weekly class hours is under 9 hours
				if(id == 1) {
					TandF = 1500 * time;
					creditF = 1200 * time; 
				}
				else {
					TandF = 2250 * time;
					creditF = 1800 * time;
				}
			}
			else goto BEGIN; // Else is same as the student in 2~4 grade, jump to the flag "BEGIN"
		}
		else {
			BEGIN: 
			if (id == 1) { // for the users who are local or overseas Chinese students
				if (col == 1 || col == 2) {
					if (grd == 1) tuition = 17680 + 500;
					else tuition = 17680;
					if (col == 1) MFee = 11310;
					else MFee = 11060; 
				}
				else {
					if (grd == 1) tuition = 17510 + 500;
					else tuition = 17510;
					MFee = 7260;
				} 
			}
			else if (id == 2) { // for the users who are international or China students
				if (col == 1 || col == 2) {
					if (grd == 1) tuition = 35360 + 500;
					else tuition = 35360;
					if (col == 1) MFee = 22620;
					else MFee = 22120; 
				}
				else {
					if (grd == 1) tuition = 35020 + 500;
					else tuition = 35020;
					MFee = 14520;
				} 
			}
		}
	}
	else if (pro == 2) { // for the users in the graduate programs 
		// Prompt the users to select their colleges or Institutes, save the result in variable "col"
		cout<<"Please select the college/institute for your major"<<endl;
		printName(pro);
		cout<<"ANS: ";
		cin>>col;
		system("cls");
		
		if(col == 3) { // music individual instruction class
			cout<<"Are you major in the Institute of Music? (y/n): ";
			if(cin.get() == 'y') {
				cout<<"Have you applied for the individual instrucion class this semester? (y/n): ";
				if (cin.get() == 'y') musicF = 11670;
			}
		}
		system("cls");
		
		// Prompt user to enter their total credit point and save it in variable "time"
		cout<<"Please enter the total credit points in your major: ";
		cin>>time;
		system("cls");
		
		if(id == 1) { // for local and over-seas Chinese students 
			if(col == 1) TandF = 13470;
			else TandF = 12980;
			if(col == 4) creditF = 3000 * time;
			else creditF = 1590 * time;
		}
		else if (id == 2) { // for international and PROC students
			if(col == 1) TandF = 26940;
			else TandF = 25960;
			if(col == 4) creditF = 3180 * time;
			else creditF = 2385 * time;
		}
		
		int col2 = 0, time2 = 0; // Declare variables for the 'minoring' condition
		
		cout<<"Do you have any minor? (y/n): ";
		if(cin.get() == 'y') { // if the user has minor, prompt the user to select their minoring intstitute
			cout<<"Please select the college/institute for your minor"<<endl;
			printName(pro);
			cout<<"ANS: ";
			cin>>col2;
		}
		if(col2 != 0) { //for minor
			cout<<"Please enter the total credit points in your minor: ";
			cin>>time2;
			if(id == 1) { // for local and over-seas Chinese students
				if (col2 == 4) creditF += 3000 * time2;
				else creditF += 1590 * time2;
			}
			else if(id == 2) { // for international and PROC students
				if(col2 == 4) creditF += 3180 * time2;
				else creditF += 2385 * time2;
			}
		}
	}
	else { // In-service
		cout<<"Please select your college/department"<<endl; 
		printName(pro);
		cout<<"Ans:";
		cin>>col;
		system("cls");
			
		// Consider differrent condition for different TendF and creditF
		if(col==1){
			TandF = 13470 ;
			creditF = 6000 * time ;
		}	
		if(col==2){
			TandF = 12980 ;
			creditF = 5000 * time ;
		}	
		if(col==3){
			TandF = 12980 ;
			creditF = 6000 * time ;
		}	
		if(col==4){
			TandF = 12980 ;
			creditF = 7000 * time ;
		}	
		if(col==5){
			TandF = 12980 ;
			creditF = 6500 * time ;
		}	
		if(col==6){
			TandF = 12980 ;
			creditF = 7200 * time ;
		}	
		if(col==7){
			TandF = 12980 ;
			creditF = 7000 * time ;
		}
		if(col==8){
			TandF = 13470 ;
			creditF = 5000 * time ;
		}
		if(col==9){
			TandF = 12980 ;
			creditF = 10000 * time ;
		}
	}
	// Edu Program
	int eduF = 0, time3 = 0;
	cout<<"Have you applied for the Teaching Programs? (y/n) ";
	if(cin.get() == 'y') {
		cout<<"Please enter the credit points in your Education Program: ";
		cin>>time3;
		if(id == 1) eduF = 1200 * time3; 
		else eduF = 1800 * time3;
	}
	
	// Showing the result, calls function printReceipt
	system("cls");
	printReceipt(acc, tuition, MFee, TandF, creditF, musicF, eduF);
	
	return 0;
} // end of main
void printName(int num) { // Print name of college/department/institute
	if (num == 1) {
		cout<<"[1] Colleges of Electrical and Computer Engineering"<<endl;
		cout<<setw(4)<<""<<"Colleges of Computer Science"<<endl;
		cout<<setw(4)<<""<<"Colleges of Engineering"<<endl;
		cout<<setw(4)<<""<<"Colleges of Photonics"<<endl;
		cout<<setw(4)<<""<<"Colleges of Biological Science and Technology"<<endl;
		cout<<setw(4)<<""<<"Departments of Electrophysics"<<endl;
		cout<<setw(4)<<""<<"Departments of Applied Chemistry"<<endl;
		cout<<setw(4)<<""<<"Department of Transportation and Logistics Management"<<endl<<endl;
		cout<<"[2]"<<" Departments of Applied Mathematics"<<endl;
		cout<<setw(4)<<""<<"College of Management"<<endl<<endl;
		cout<<"[3]"<<" College of Humanities and Social Sciences"<<endl;
		cout<<setw(4)<<""<<"College of Hakka Studies"<<endl;
	}
	else if (num == 2) {
		cout<<"[1] Colleges of Electrical and Computer Engineering"<<endl;
		cout<<setw(4)<<""<<"Colleges of Computer Science"<<endl;
		cout<<setw(4)<<""<<"Colleges of Engineering"<<endl;
		cout<<setw(4)<<""<<"Colleges of Photonics"<<endl;
		cout<<setw(4)<<""<<"Colleges of Biological Science and Technology"<<endl;
		cout<<setw(4)<<""<<"College of Technology Law"<<endl;
		cout<<setw(4)<<""<<"International College of Semiconductor Technology"<<endl;
		cout<<setw(4)<<""<<"College of Artificial Intelligence and Green Energy"<<endl;
		cout<<setw(4)<<""<<"Department of Transportation and Logistics Management"<<endl;
		cout<<setw(4)<<""<<"Departments of Electrophysics"<<endl;
		cout<<setw(4)<<""<<"Departments of Applied Chemistry"<<endl;
		cout<<setw(4)<<""<<"International Master of Science Program for Interdisciplinary"<<endl;
		cout<<setw(4)<<""<<"Molecular Science of Materials and Chemical Biology"<<endl;
		cout<<setw(4)<<""<<"International Graduate Degree Program of Sustainable Chemical"<<endl;
		cout<<setw(4)<<""<<"Science and Technology"<<endl<<endl;
		cout<<"[2] Departments of Applied Mathematics"<<endl;
		cout<<setw(4)<<""<<"Institute of Statistics, Institute of Physics"<<endl;
		cout<<setw(4)<<""<<"College of Management"<<endl<<endl;
		cout<<"[3] College of Humanities and Social Sciences"<<endl;
		cout<<setw(4)<<""<<"College of Hakka Studies"<<endl<<endl;
		cout<<"[4] Degree Program of Global Business Administration"<<endl;
	}
	else {
		cout<<"請選擇就讀的學院在職專班"<<endl;
		cout<<"[1] 電機學院在職專班"<<endl;
		cout<<setw(4)<<""<<"資訊學院在職專班"<<endl;
		cout<<setw(4)<<""<<"工學院在職專班"<<endl;
		cout<<setw(4)<<""<<"科技法律學院在職專班"<<endl;
		cout<<"[2] 理學院在職專班"<<endl;
		cout<<setw(4)<<""<<"客家文化學院在職專班"<<endl;
		cout<<"[3] 管理科學組在職專班"<<endl;
		cout<<setw(4)<<""<<"運輸物流組在職專班"<<endl;
		cout<<setw(4)<<""<<"經營管理組在職專班"<<endl;
		cout<<"[4] 工業工程與管理組在職專班"<<endl;
		cout<<"[5] 資訊管理組在職專班"<<endl;
		cout<<"[6] 科技管理組在職專班"<<endl;
		cout<<"[7] 財務金融組在職專班"<<endl;			
		cout<<"[8] 光電學院在職專班"<<endl;
		cout<<"[9] 高階主管管理碩士學程(EMBA)"<<endl;
	}
} // end of printName
void printReceipt(int name, int f1, int f2, int f3, int f4, int f5, int f6) { // Print out receipt 
	cout<<setw(15)<<""<<"Receipt"<<setw(10)<<""<<"Student ID: "<<name<<endl;
	cout<<"=================================================="<<endl;
	cout<<setw(4)<<""<<"Tuition: "<<f1<<endl;
	cout<<setw(4)<<""<<"Miscellaneous Fees: "<<f2<<endl;
	cout<<setw(4)<<""<<"Tuition and Miscellaneous Fees: "<<f3<<endl;
	cout<<setw(4)<<""<<"Credit points Fees: "<<f4<<endl;
	cout<<setw(4)<<""<<"Individual Instruction Fees: "<<f5<<endl;
	cout<<setw(4)<<""<<"Teaching Credit Fees: "<<f6<<endl;
	cout<<"=================================================="<<endl;
	cout<<setw(4)<<""<<"Total: "<<f1 + f2 + f3 + f4 + f5 + f6;
} // end of printReceipt
