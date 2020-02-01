#include <iostream>

using namespace std;

int main()
{
	int feet = 0; 
	
	double inch = 0, height = 0, Dfeet = 0;
	

	cout<<"키를 입력하시오.(피트):";
	cin>>feet;
	cout<<"키를 입력하시오.(인치):";
	cin>>inch;

	height = (inch + feet*12)*2.54;

	cout<<feet<<"피트 "<<inch<<"인치는 "<<height<<" cm입니다."<<endl;
	

	return 0;
}