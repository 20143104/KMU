#include <iostream>

using namespace std;

int main()
{
	float saving = 0, rate = 0, result = 0, temp = 0;

	

	cout<<"예금액을 입력하시오: ";
	cin>>saving;
	cout<<"연이율을 입력하시오(단위 퍼센트): ";
	cin>>rate;
	temp = saving + (saving * (rate/100));
	result = temp + (temp * (rate/100));

	cout<<"2년 후의 예금액은 "<<result<<"입니다."<<endl;
		

	return 0;
}