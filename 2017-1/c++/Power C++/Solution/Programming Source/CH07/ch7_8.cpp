#include <iostream>

using namespace std;

void cylinder(double &loan, double rate);

int main ()
{
	double l = 0;
	double &loan = l, rate = 0;

	
	cout<<"대출 금액을 입력하시오 : ";
	cin>>loan;
	cout<<"연 이율을 입력하시오 : ";
	cin>>rate;
	cylinder(loan, rate);
	cout<<"한 달 이자는 "<<loan<<"입니다."<<endl;
	return 0;
}
void cylinder(double &loan, double rate)
{
	rate = rate/12/100;
	loan = loan*rate;
}