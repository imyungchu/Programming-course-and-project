// Function Name : Budget 
// Version: 0.2 
// Function Describe: 
//   (1).�i�sŪ�ɪ��w��p��{�� .       
// Modified by:    ������               MDate: 2020-06-17

#include <iostream>
#include <string> 
#include <fstream> 
#include <iomanip>

using namespace std;

int main() {
	
	//�ܼư� 
	int budget; 
	int spended = 0; 
	string item;
	int itemspended = 0;
	int noi=1;
	
	//SP1.�ˬd�w������� Budget.txt �O�_�s�b
	//�s�b���ܡA�NŪ��(�έp��)�g�J�ܼ� 
	
	fstream myfile;
	myfile.open("Budget.txt", ios::in); //��Ū�ɮ�
	if(myfile.good()){
	myfile >> budget ; //Ū�Xbudget����
	while(myfile.peek()!=EOF){
	myfile>>item;
	myfile>>itemspended;
	spended=spended+itemspended;
	 myfile.close();
	 }
	
	
	}
	//�p��s���Ѿlbudget
	/*while(myfile.eof()){
	myfile >> item ;
	myfile >> itemspended ;
	spended = spended + itemspended ;*/

	//myfile >> spended ;
	else{
	//���s�b���ܡA�N�ШϥΪ̿�J�w���`��
	cout << "�п�J�������o���w���`��:";
	cin >> budget; 
	//Obudget = budget;
	
	//SP2.�إߤ@�ӹw�������Budget.txt�A�ñN�w���`�Ƽg�J 
	
	myfile.open("Budget.txt",ios::out); //�g�J�w���`��
	myfile << budget <<endl;//�s�Jbudget���� 
	myfile.close();
    }
	
	
	//�}�l��s��O���� 
	cout<<endl;
	do {
		
	   	cout << "�ثe���w��|���G" << (budget-spended) << "��" << endl; 
	    cout << "�п�J��O�w�⪺���ث~�W(exit�N�����})�G" << endl; 
		cin >> item;
		
		 
		
		if (item != "exit") { //�����ث~�W���� 
		
			cout << "�п�J���ءG" << item << "����O�G" << endl; 
		    cin >> itemspended;
			//spended = spended + itemspended;
			
	/*myfile.open("Budget.txt",ios::out|ios::trunc);
	
	budget = budget - spended ; //�g�J�w���`��
	
	myfile << budget <<endl;//�s�Jbudget���� 
	myfile.close();*/
			
  		    //��w���٬O�i���������p 
		    if (itemspended <= (budget - spended)) {
		    //SP3.�}�ɰO���ӵ����(hint:�n�}���[�Ҧ�) 
			myfile.open("Budget.txt",ios::out|ios::app);
			//myfile << budget <<endl;
			//myfile << noi <<endl;
			myfile <<  "\n" << item ;
			myfile <<  "\n" << itemspended;
			//myfile << spended <<endl;
			myfile.close();
		    } 
		    else {
		    	cout << "�W�X�w��" <<endl;
		    	continue;
			}
			spended = spended + itemspended;
		}
	cout << endl;
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
	/*myfile.open("Budget.txt", ios::in);
	myfile >> budget ; //Ū�Xbudget���� 
	myfile >> noi ;
	
	myfile.close();*/
	
	//�C�X�ثe���w���X����
	cout << "�`�w��G"<<budget<<"��" <<endl;
	/*while (true){
	char x;
	x=myfilei.get();
	if(x=='\n')
		break;
	cout<<x;
	
	}*/
	cout << "�ثe�w��O�G"<< spended <<"�� " <<"	�|�l�G"<<budget-spended<<"��"<<endl;
	cout << "\n==��X����============================"<<endl;
	myfile.open("Budget.txt",ios::in); 
	myfile >> budget ;//Ūbudget���� 
	while(myfile.peek()!=EOF){
		myfile>>item;
		myfile>>itemspended;
		cout<< noi <<setw(4)<<item<<setw(8)<<itemspended<<endl;
		noi++;
	}
	myfile.close();
	//for (int i=1;i<=noi;i++)
	//cout << i << setw(4) <<item <<setw(8) <<itemspended;
	/*while (!myfilei.eof()){//Ū�X�ɮ׸̪����� ���ɮרS���������~����� 
	
		char x;
		x=myfilei.get();
		if(x==' ') {//��Ū��ťծɴ��U�Ӹ�� 
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
