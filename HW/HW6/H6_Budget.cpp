#include <iostream>
#include <string> 
 
using namespace std;

int main() {
	
	//�ܼư� 
	int budget; 
	int spended = 0; 
	string item;
	int itemspended = 0;
	
	//SP1.�ˬd�w������� Budget.txt �O�_�s�b
	//�s�b���ܡA�NŪ��(�έp��)�g�J�ܼ� 
	
	
	
	//���s�b���ܡA�N�ШϥΪ̿�J�w���`��
	cout << "�п�J�������o���w���`��:";
	cin >> budget; 
	
	//SP2.�إߤ@�ӹw�������Budget.txt�A�ñN�w���`�Ƽg�J 


	//�}�l��s��O���� 
	do {
	
	   	cout << "�ثe���w��|���G" << (budget-spended) << "��" << endl; 
	
  	    
	    cout << "�п�J��O�w�⪺���ث~�W(exit�N�����})�G" << endl; 
		cin >> item;
		
		if (item != "exit") { //�����ث~�W���� 
		
			cout << "�п�J���ءG" << item << "����O�G" << endl; 
		    cin >> itemspended;
		
  		    //��w���٬O�i���������p 
		    if (itemspended <= (budget - spended)) {
		        //SP3.�}�ɰO���ӵ����(hint:�n�}���[�Ҧ�) 
		   
		   
		   
		    } 
		
		    spended = spended + itemspended; 
		} 

	
	} while(item!="exit"); 
	
	
    //�C�X�ثe���w���X���� 
    //�榡�p�U�G 
	// 
	//�`�w��G5600�� 
	//�ثe�w��O�G4200��  �|�l�G1400��
	// 
	//==��X����============================
	// 1       A4��          1000
	// 2       �v�L           600
	// 3       ���           800     
    // 4       ����           300
	// 5     ������          1500 
	//====================================== 

	return 1;
}
