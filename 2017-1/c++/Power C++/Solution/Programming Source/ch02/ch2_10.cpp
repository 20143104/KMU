#include <iostream>

using namespace std;

int main()
{
	int start = 0, end = 0, mileage = 0, fuel = 0;
	

	cout<<"출발한 지점의 주행거리계.: ";
	cin>>start;
	cout<<"도착한 지점의 주행거리계.: ";
	cin>>end;
	cout<<"사용한 연료: ";
	cin>>fuel;
	
	mileage = (end - start)/fuel;

	cout<<"연비는 "<<mileage<<"km/l입니다."<<endl;
		

	return 0;
}