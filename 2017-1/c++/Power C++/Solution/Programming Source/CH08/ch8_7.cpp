#include <iostream>
#define PI 3.141592

using namespace std;

double CircleArea(double);

int main()
{
	bool state = true;
	double radius = 0;
	char con;
	while(state){
		cout<<"원의 반지름을 입력하시오 : ";
		cin>>radius;
		cout<<"원의 반지름은 "<<CircleArea(radius)<<"입니다."<<endl;
		cout<<"계속 하시겠습니까?(Y/N)";
		cin>>con;
		if(con == 'Y' || con == 'y'){
			state = true;
		}
		else if(con == 'N' || con == 'n'){
			state = false;
		}
	}

	return 0;
}

double CircleArea(double r)
{
	return r*r*PI;
}