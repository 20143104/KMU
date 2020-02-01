#include <iostream>

using namespace std;

int main()
{
	double x = 0, y = 0;

	cout<<"x의 값을 입력하시오:";
	cin>>x;

	y = (3*x*x*x)-(7*x*x)+9;

	cout<<"값은 "<<y<<" 입니다."<<endl;

	return 0;
}