#include <iostream>

using namespace std;

int main()
{
	int bir_y, bir_m, bir_d;
	int today_y, today_m, today_d;
	int age;
	
	cout<<"사용자가 생일을 입력하세요 (예 1990 10 12) : ";
	cin>>bir_y>>bir_m>>bir_d;

	cout<<"현재 날짜를 입력하세요 (예 2010 09 15) : ";
	cin>>today_y>>today_m>>today_d;
	
	
	if ( bir_m > today_m )
		age = today_y - bir_y;
	else if ( bir_m < today_m )
		age = today_y - bir_y - 1;
	else{
		if ( bir_d <= today_d )
			age = today_y - bir_y - 1;
		else
			age = today_y - bir_y;
	}
	
	cout<<"당신의 나이는 : "<<age<<endl;
	
	return 0;	
}
