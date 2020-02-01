#include <iostream>
using namespace std;
void add_tax(double &salary, double rate = 20);

int main ()
{
	double sal = 0, rate = 0;
	double &salary = sal;
	
	cout<<"급여를 입력하시오 : ";
	cin>>salary;
	cout<<"세율을 입력하시오 : ";
	cin>>rate;
	add_tax(salary,rate);
	cout<<"소득세는 "<<salary<<"입니다."<<endl;
	
	return 0;
}
void add_tax(double &salary, double rate)
{
	rate = rate/100;
	salary = salary*rate;
}