#include <iostream>
#include <cmath>

using namespace std;

void quad_eqn(double a, double b, double c);

int main()
{
	double a = 0,b = 0,c = 0;

	cout<<"2�� �������� ����� �Է��Ͻÿ�."<<endl;
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
			cout<<"���� �����ϴ�."<<endl;
		}
		else{
			cout<<"���� "<<result2<<"�Դϴ�."<<endl;
		}
	}
	else if(result2 < 0){
		cout<<"���� "<<result1<<"�Դϴ�."<<endl;
	}
	else{
		cout<<"���� "<<result1<<"�� "<<result2<<"�Դϴ�."<<endl;
	}

}