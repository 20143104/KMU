#include <iostream>

using namespace std;

int main()
{
	int start = 0, end = 0, mileage = 0, fuel = 0;
	

	cout<<"����� ������ ����Ÿ���.: ";
	cin>>start;
	cout<<"������ ������ ����Ÿ���.: ";
	cin>>end;
	cout<<"����� ����: ";
	cin>>fuel;
	
	mileage = (end - start)/fuel;

	cout<<"����� "<<mileage<<"km/l�Դϴ�."<<endl;
		

	return 0;
}