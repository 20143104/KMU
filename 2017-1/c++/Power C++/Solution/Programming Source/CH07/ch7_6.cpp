#include <iostream>
using namespace std;
void add_tax(double &salary, double rate = 20);

int main ()
{
	double sal = 0, rate = 0;
	double &salary = sal;
	
	cout<<"�޿��� �Է��Ͻÿ� : ";
	cin>>salary;
	cout<<"������ �Է��Ͻÿ� : ";
	cin>>rate;
	add_tax(salary,rate);
	cout<<"�ҵ漼�� "<<salary<<"�Դϴ�."<<endl;
	
	return 0;
}
void add_tax(double &salary, double rate)
{
	rate = rate/100;
	salary = salary*rate;
}