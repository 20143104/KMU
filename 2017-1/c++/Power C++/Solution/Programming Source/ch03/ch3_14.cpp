#include <iostream>
using namespace std;
int main()
{
	double tax = 0;
	
	cout<<"�ҵ��� �Է��ϼ��� : ";
	cin>>tax;

	if( tax <= 1000){
		cout<<"�ҵ漼�� "<< tax*0.08 <<"�Դϴ�.!"<<endl;
	}
	else if(tax >=1000 && tax <=4000){
		cout<<"�ҵ漼�� "<< tax*0.17 <<"�Դϴ�.!"<<endl;
	}
	else if(tax > 4000 && tax <=8000){
		cout<<"�ҵ漼�� "<< tax*0.26 <<"�Դϴ�.!"<<endl;
	}
	else if(tax > 8000){
		cout<<"�ҵ漼�� "<< tax*0.35 <<"�Դϴ�.!"<<endl;

	}
	return 0;
}
