#include <iostream>

#define PI  3.14159265

using namespace std;

int main()
{
	double radius = 0, volume = 0, area = 0;

	

	cout<<"���� �������� �Է��Ͻÿ�: ";
	cin>>radius;
	
	area = 4*PI*radius*radius;
	volume = 4/3*PI*radius*radius*radius;

	cout<<"���� ǥ������ "<<area<<"�Դϴ�."<<endl;
	cout<<"���� ü���� "<<volume<<"�Դϴ�."<<endl;
		

	return 0;
}