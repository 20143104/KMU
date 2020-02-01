#include <iostream>
#include <cmath>

using namespace std;

void quad_eqn(double a, double b, double c);

int main()
{
	double a = 0,b = 0,c = 0;

	cout<<"2차 방정식의 계수를 입력하시오."<<endl;
	cout<<"a: ";
	cin>>a;
	cout<<"b: ";
	cin>>b;
	cout<<"c: ";
	cin>>c;

	quad_eqn(a,b,c);

	return 0;
}

void quad_eqn(double a, double b, double c)
{
	double result1 = 0,result2 = 0;
	result1 = (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
	result2 = (-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
	
	if(result1 < 0){
		if(result2 < 0){
			cout<<"근이 없습니다."<<endl;
		}
		else{
			cout<<"근은 "<<result2<<"입니다."<<endl;
		}
	}
	else if(result2 < 0){
		cout<<"근은 "<<result1<<"입니다."<<endl;
	}
	else{
		cout<<"근은 "<<result1<<"와 "<<result2<<"입니다."<<endl;
	}

}