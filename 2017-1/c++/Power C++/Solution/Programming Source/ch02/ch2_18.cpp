#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	double result1 = 0, result2 = 0;

	cout<<"ax^2 + bx + c "<<endl;
	cout<<"a를 입력하시오: ";
	cin>>a;
	cout<<"b를 입력하시오: ";
	cin>>b;
	cout<<"c를 입력하시오: ";
	cin>>c;

	result1 = (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
	result2 = (-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);

	
	

	cout<<"이차방정식의 근은 "<<result1<<"또는 "<<result2<<"입니다."<<endl;
	
		

	return 0;
}