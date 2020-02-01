#include <iostream>
using namespace std;
int main()
{
	double tax = 0;
	
	cout<<"소득을 입력하세요 : ";
	cin>>tax;

	if( tax <= 1000){
		cout<<"소득세는 "<< tax*0.08 <<"입니다.!"<<endl;
	}
	else if(tax >=1000 && tax <=4000){
		cout<<"소득세는 "<< tax*0.17 <<"입니다.!"<<endl;
	}
	else if(tax > 4000 && tax <=8000){
		cout<<"소득세는 "<< tax*0.26 <<"입니다.!"<<endl;
	}
	else if(tax > 8000){
		cout<<"소득세는 "<< tax*0.35 <<"입니다.!"<<endl;

	}
	return 0;
}
