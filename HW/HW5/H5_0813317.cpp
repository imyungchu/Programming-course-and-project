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

int NoDigits(int x);//�λ��j�p��ǤJ��Ʀ��Xdigits�C
int DelDigit(int x, int delD);//��J�@��ưѼƤΫ��w�䤤�@�Ӧ�ơA�Ө禡�|�Ǧ^�����Ӧ�ƪ���Ƶ��I�s�̡C
int GetDigit(int Target,int num);
void TheSameDigits(int x,int overhead = -1);
//�b�D�禡main���A���ܨín�D�ϥΪ̿�J�@�Ӿ�ơA�M��I�sTheSameDigits�Ӷi��Ҧ��ۦP�Ʀr���Ҧ���ƦC��C
int main(){
	int x;
	cout<< " Please input an integer : ";
	cin >> x;
	cout<< "All integers have the same digits with 123 are : "<<endl;
	TheSameDigits(x,-1);//Function with "void" can't use "cout"operator. 
	return 0 ;
}

//�ҡG��J123�A�禡�^��3�F��J1234�A�禡�^��4�C
int NoDigits(int x){
	int dig = 1;
	while(x>10){
	NoDigits(x/10);
	x = x / 10 ;
	dig++;
	}
	return dig ;
}
//�ҡG��J123�Ϋ��w��2��A�禡�^�Ǿ��13�F��J1234�Ϋ��w��4��A�禡�^�Ǿ��234�C
int DelDigit(int x, int delD){
	int a,b;
	int d =(pow(10,delD));
	int e = (pow(10,delD-1));
	a = x / d;
	b = x % e;
return (a*e+b);
}
//Get the 'digit n' in the number 'm' , ���o�Ʀrm����n�� 
int GetDigit(int m,int n){
	int y = pow(10,n-1);//��X10��n-1����  �Ҧpm=4567,n=2,y=10^(2-1)=10
	int a = m / y;//�Ҧpm=4567,a=4567/10=456 
	return a % 10;//456%10=6 �Y�OGetDigit(4567,2) 
}
//�Q�ΥH�W�G�Ө禡�A�Ψϥλ��j����k�A���g�X�禡TheSameDigits�A�Ө禡����J�ѼơA�ݦܤ֦��@�ӥؼЪ����
void TheSameDigits(int x,int overhead ){
	int d = NoDigits(x);//��ƽեΪ��ɭԤ��n��int�A��Ʃw�q�ɤ~�ݭn�C
	if(d==1){
		cout << overhead << x << endl;
		return;
	}
	for (int i = 1 ; i <= d ; i++){ //�X��ƴN�`���X�� 
		int f = GetDigit(x,i); //���i��Ʀr���X�� �s�b f �� 
		int b ;
		if (overhead == -1){
			b = f ;//�p�G�᭱b�O�Ū� ��f���w��b 
		}
		else{
			b = overhead * 10 + f; // �� b �ܦ� bf ,ex: b=12*10 + 3 =123 
		}
		TheSameDigits(DelDigit(x,i),b);//���j�I�s:����x����Ƶ���1�A��Xb�Mx �C��i���P�A�����P���ƨ�᭱�A�i�ƦC 
	}

}

