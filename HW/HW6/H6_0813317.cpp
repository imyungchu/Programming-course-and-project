// Function Name : Budget 
// Version: 0.2 
// Function Describe: 
//   (1).可存讀檔的預算計算程式 .       
// Modified by:    江詠筑               MDate: 2020-06-17

#include <iostream>
#include <string> 
#include <fstream> 
#include <iomanip>

using namespace std;

int main() {
	
	//變數區 
	int budget; 
	int spended = 0; 
	string item;
	int itemspended = 0;
	int noi=1;
	
	//SP1.檢查預算明細檔 Budget.txt 是否存在
	//存在的話，就讀取(或計算)寫入變數 
	
	fstream myfile;
	myfile.open("Budget.txt", ios::in); //唯讀檔案
	if(myfile.good()){
	myfile >> budget ; //讀出budget的值
	while(myfile.peek()!=EOF){
	myfile>>item;
	myfile>>itemspended;
	spended=spended+itemspended;
	 myfile.close();
	 }
	
	
	}
	//計算新的剩餘budget
	/*while(myfile.eof()){
	myfile >> item ;
	myfile >> itemspended ;
	spended = spended + itemspended ;*/

	//myfile >> spended ;
	else{
	//不存在的話，就請使用者輸入預算總數
	cout << "請輸入本次取得的預算總數:";
	cin >> budget; 
	//Obudget = budget;
	
	//SP2.建立一個預算明細檔Budget.txt，並將預算總數寫入 
	
	myfile.open("Budget.txt",ios::out); //寫入預算總數
	myfile << budget <<endl;//存入budget的值 
	myfile.close();
    }
	
	
	//開始更新花費明細 
	cout<<endl;
	do {
		
	   	cout << "目前的預算尚有：" << (budget-spended) << "元" << endl; 
	    cout << "請輸入花費預算的項目品名(exit代表離開)：" << endl; 
		cin >> item;
		
		 
		
		if (item != "exit") { //有項目品名的話 
		
			cout << "請輸入項目：" << item << "的花費：" << endl; 
		    cin >> itemspended;
			//spended = spended + itemspended;
			
	/*myfile.open("Budget.txt",ios::out|ios::trunc);
	
	budget = budget - spended ; //寫入預算總數
	
	myfile << budget <<endl;//存入budget的值 
	myfile.close();*/
			
  		    //當預算還是可支應的狀況 
		    if (itemspended <= (budget - spended)) {
		    //SP3.開檔記錄該筆資料(hint:要開附加模式) 
			myfile.open("Budget.txt",ios::out|ios::app);
			//myfile << budget <<endl;
			//myfile << noi <<endl;
			myfile <<  "\n" << item ;
			myfile <<  "\n" << itemspended;
			//myfile << spended <<endl;
			myfile.close();
		    } 
		    else {
		    	cout << "超出預算" <<endl;
		    	continue;
			}
			spended = spended + itemspended;
		}
	cout << endl;
	} while(item!="exit"); 
	
    //列出目前的預算支出明細 
    //格式如下： 
	// 
	//總預算：5600元 
	//目前已花費：4200元  尚餘：1400元
	// 
	//==支出明細============================
	// 1       A4紙          1000
	// 2       影印           600
	// 3       文具           800     
    // 4       紅筆           300
	// 5     炭粉夾          1500 
	//====================================== 
	/*myfile.open("Budget.txt", ios::in);
	myfile >> budget ; //讀出budget的值 
	myfile >> noi ;
	
	myfile.close();*/
	
	//列出目前的預算支出明細
	cout << "總預算："<<budget<<"元" <<endl;
	/*while (true){
	char x;
	x=myfilei.get();
	if(x=='\n')
		break;
	cout<<x;
	
	}*/
	cout << "目前已花費："<< spended <<"元 " <<"	尚餘："<<budget-spended<<"元"<<endl;
	cout << "\n==支出明細============================"<<endl;
	myfile.open("Budget.txt",ios::in); 
	myfile >> budget ;//讀budget的值 
	while(myfile.peek()!=EOF){
		myfile>>item;
		myfile>>itemspended;
		cout<< noi <<setw(4)<<item<<setw(8)<<itemspended<<endl;
		noi++;
	}
	myfile.close();
	//for (int i=1;i<=noi;i++)
	//cout << i << setw(4) <<item <<setw(8) <<itemspended;
	/*while (!myfilei.eof()){//讀出檔案裡的明細 當檔案沒有結束時繼續執行 
	
		char x;
		x=myfilei.get();
		if(x==' ') {//當讀到空白時換下個資料 
		 x=myfilei.get();
		 cout<<setw(8)<<x;
		}
		else if(x=='\n')//change line
			cout<<endl;
		else 
			cout<<x;
	}*/
	cout << "\n======================================";
	
	
	return 1;
}
