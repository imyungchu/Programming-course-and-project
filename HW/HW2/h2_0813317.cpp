//�ɦW : H2_0813317.cpp
//�}�o�� : ������             �}�o�ɶ� : 2020/03/25 
//�{���X�W��  : �G���@���������  �{������ : ���Nabc�A�by = a*x*x + b*x + c�������� 
#include<iostream>
#include<math.h>
using namespace std ;
int main()
{
	//�C�L�Xy = a*x*x + b*x + c���B�⦡�C
	cout << " y = a*x*x + b*x + c" <<endl;
	//���ܨín�D�ϥΪ̿�J�n�p�⪺a, b, c�T�Y�ơC
	float a , b , c ;
	cout << " �п�Ja " <<endl;
	cin >> a  ;
	cout << " �п�Jb " <<endl;
	cin >> b  ;
	cout << " �п�Jc " <<endl;
	cin >> c  ;
	//�p��ÿ�X�G�Ӹ�x1, x2�A�ϱoy(x1 or x2) = 0�C
	float D = b*b - 4 *a*c ;
	if (D < 0)
	cout << " ����{���L�� " ; //�P�O���p��s:�L�� 
	else 
	{
	cout << " ����{������ӸѬ� : \n" ;
	cout << "X1=" << ((-b)+ sqrt(D))/2*a <<endl;
	cout << "X2=" << ((-b)- sqrt(D))/2*a <<endl;
	}
	
	return 0 ;
}
 
