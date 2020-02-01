#include <iostream>

using namespace std;

int main()
{
	int feet = 0; 
	
	double inch = 0, height = 0, Dfeet = 0;
	

	cout<<"키를 입력하시오.:";
	cin>>height;

	feet = height/30.48;
	Dfeet = height/30.48;
	inch = (Dfeet - feet)*12;

	cout<<height<<"cm는 "<<feet<<"피트 "<<inch<<" 인치입니다."<<endl;
	

	return 0;
}