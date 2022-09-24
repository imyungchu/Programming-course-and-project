//檔名 : H2_0813317.cpp
//開發者 : 江詠筑             開發時間 : 2020/03/25 
//程式碼名稱  : 二元一次式的兩根  程式說明 : 任意abc，在y = a*x*x + b*x + c的公式解 
#include<iostream>
#include<math.h>
using namespace std ;
int main()
{
	//列印出y = a*x*x + b*x + c的運算式。
	cout << " y = a*x*x + b*x + c" <<endl;
	//提示並要求使用者輸入要計算的a, b, c三係數。
	float a , b , c ;
	cout << " 請輸入a " <<endl;
	cin >> a  ;
	cout << " 請輸入b " <<endl;
	cin >> b  ;
	cout << " 請輸入c " <<endl;
	cin >> c  ;
	//計算並輸出二個解x1, x2，使得y(x1 or x2) = 0。
	float D = b*b - 4 *a*c ;
	if (D < 0)
	cout << " 此方程式無解 " ; //判別式小於零:無解 
	else 
	{
	cout << " 此方程式的兩個解為 : \n" ;
	cout << "X1=" << ((-b)+ sqrt(D))/2*a <<endl;
	cout << "X2=" << ((-b)- sqrt(D))/2*a <<endl;
	}
	
	return 0 ;
}
 
