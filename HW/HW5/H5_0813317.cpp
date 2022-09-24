// Function Name : recursive output's combination
// Version: 0.1 
// Function Describe: 
//   (1).use  function to generate numbers with all integers have the same digits . 
//   (2).use recursive function to count the digits of numbers .     
// Create by:  Yung-chu,chiang         CDate: 2020-05-23 
// Modified by:                        MDate: 

#include <iostream>
#include <cmath>
using namespace std;

int NoDigits(int x);//用遞迴計算傳入整數有幾digits。
int DelDigit(int x, int delD);//輸入一整數參數及指定其中一個位數，該函式會傳回除掉該位數的整數給呼叫者。
int GetDigit(int Target,int num);
void TheSameDigits(int x,int overhead = -1);
//在主函式main中，提示並要求使用者輸入一個整數，然後呼叫TheSameDigits來進行所有相同數字的所有整數列表。
int main(){
	int x;
	cout<< " Please input an integer : ";
	cin >> x;
	cout<< "All integers have the same digits with 123 are : "<<endl;
	TheSameDigits(x,-1);//Function with "void" can't use "cout"operator. 
	return 0 ;
}

//例：輸入123，函式回傳3；輸入1234，函式回傳4。
int NoDigits(int x){
	int dig = 1;
	while(x>10){
	NoDigits(x/10);
	x = x / 10 ;
	dig++;
	}
	return dig ;
}
//例：輸入123及指定第2位，函式回傳整數13；輸入1234及指定第4位，函式回傳整數234。
int DelDigit(int x, int delD){
	int a,b;
	int d =(pow(10,delD));
	int e = (pow(10,delD-1));
	a = x / d;
	b = x % e;
return (a*e+b);
}
//Get the 'digit n' in the number 'm' , 取得數字m的第n位 
int GetDigit(int m,int n){
	int y = pow(10,n-1);//輸出10的n-1次方  例如m=4567,n=2,y=10^(2-1)=10
	int a = m / y;//例如m=4567,a=4567/10=456 
	return a % 10;//456%10=6 即是GetDigit(4567,2) 
}
//利用以上二個函式，及使用遞迴的方法，撰寫出函式TheSameDigits，該函式的輸入參數，需至少有一個目標的整數
void TheSameDigits(int x,int overhead ){
	int d = NoDigits(x);//函數調用的時候不要用int，函數定義時才需要。
	if(d==1){
		cout << overhead << x << endl;
		return;
	}
	for (int i = 1 ; i <= d ; i++){ //幾位數就循環幾次 
		int f = GetDigit(x,i); //把第i位數字拿出來 存在 f 裡 
		int b ;
		if (overhead == -1){
			b = f ;//如果後面b是空的 把f指定給b 
		}
		else{
			b = overhead * 10 + f; // 把 b 變成 bf ,ex: b=12*10 + 3 =123 
		}
		TheSameDigits(DelDigit(x,i),b);//遞迴呼叫:直到x的位數等於1，輸出b和x 每次i不同，移不同的數到後面，可排列 
	}

}

