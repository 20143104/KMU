#include <iostream>

using namespace std;

int main()
{
	int bir_y, bir_m, bir_d;
	int today_y, today_m, today_d;
	int age;
	
	cout<<"����ڰ� ������ �Է��ϼ��� (�� 1990 10 12) : ";
	cin>>bir_y>>bir_m>>bir_d;

	cout<<"���� ��¥�� �Է��ϼ��� (�� 2010 09 15) : ";
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
	
	cout<<"����� ���̴� : "<<age<<endl;
	
	return 0;	
}
