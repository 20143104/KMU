#include <iostream>


#define PI  3.14159265

using namespace std;

int main()
{
	float radius = 0.0, height = 0.0, volume = 0.0;
	

	cout<<"원기둥 밑면의 반지름을 입력하시오.: ";
	cin>>radius;
	cout<<"원기둥의 높이를 입력하시오.: ";
	cin>>height;
	
	volume = radius*radius*PI*height;

	cout<<"원기둥의 부피는 "<<volume<<"입니다."<<endl;
		

	return 0;
}