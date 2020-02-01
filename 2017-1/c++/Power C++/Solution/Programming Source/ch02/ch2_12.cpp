#include <iostream>

using namespace std;

int main()
{
	float distance = 0, min = 0, second = 0, speed = 0;

	

	cout<<"달린 거리를 입력하시오(km).: ";
	cin>>distance;
	cout<<"달린 시간 중에서 분을 입력하시오.: ";
	cin>>min;
	cout<<"달린 시간 중에서 초를 입력하시오.: ";
	cin>>second;
	
	speed = distance/((min+(second/60))/60);
	

	cout<<"평균 속도는 "<<speed<<" km/h입니다."<<endl;
		

	return 0;
}