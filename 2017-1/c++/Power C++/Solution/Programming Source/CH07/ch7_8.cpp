#include <iostream>

using namespace std;

void cylinder(double &loan, double rate);

int main ()
{
	double l = 0;
	double &loan = l, rate = 0;

	
	cout<<"���� �ݾ��� �Է��Ͻÿ� : ";
	cin>>loan;
	cout<<"�� ������ �Է��Ͻÿ� : ";
	cin>>rate;
	cylinder(loan, rate);
	cout<<"�� �� ���ڴ� "<<loan<<"�Դϴ�."<<endl;
	return 0;
}
void cylinder(double &loan, double rate)
{
	rate = rate/12/100;
	loan = loan*rate;
}