#include <iostream>

#define PI  3.14159265

using namespace std;

int main()
{
	double radius = 0, volume = 0, area = 0;

	

	cout<<"구의 반지름을 입력하시오: ";
	cin>>radius;
	
	area = 4*PI*radius*radius;
	volume = 4/3*PI*radius*radius*radius;

	cout<<"구의 표면적은 "<<area<<"입니다."<<endl;
	cout<<"구의 체적은 "<<volume<<"입니다."<<endl;
		

	return 0;
}