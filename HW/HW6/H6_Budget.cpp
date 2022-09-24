#include <iostream>
#include <string> 
 
using namespace std;

int main() {
	
	//變數區 
	int budget; 
	int spended = 0; 
	string item;
	int itemspended = 0;
	
	//SP1.檢查預算明細檔 Budget.txt 是否存在
	//存在的話，就讀取(或計算)寫入變數 
	
	
	
	//不存在的話，就請使用者輸入預算總數
	cout << "請輸入本次取得的預算總數:";
	cin >> budget; 
	
	//SP2.建立一個預算明細檔Budget.txt，並將預算總數寫入 


	//開始更新花費明細 
	do {
	
	   	cout << "目前的預算尚有：" << (budget-spended) << "元" << endl; 
	
  	    
	    cout << "請輸入花費預算的項目品名(exit代表離開)：" << endl; 
		cin >> item;
		
		if (item != "exit") { //有項目品名的話 
		
			cout << "請輸入項目：" << item << "的花費：" << endl; 
		    cin >> itemspended;
		
  		    //當預算還是可支應的狀況 
		    if (itemspended <= (budget - spended)) {
		        //SP3.開檔記錄該筆資料(hint:要開附加模式) 
		   
		   
		   
		    } 
		
		    spended = spended + itemspended; 
		} 

	
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

	return 1;
}
