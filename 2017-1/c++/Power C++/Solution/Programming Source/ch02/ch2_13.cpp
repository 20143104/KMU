#include <iostream>

using namespace std;

int main()
{
	float celsius = 0, fahrenheit = 0;

	

	cout<<"섭씨온도를 입력하시오.: ";
	cin>>celsius;
	
	fahrenheit = celsius + 273.16;

	cout<<"절대온도는 "<<fahrenheit<<"입니다."<<endl;
		

	return 0;
}