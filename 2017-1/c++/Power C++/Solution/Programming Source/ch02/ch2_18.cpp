#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	double result1 = 0, result2 = 0;

	cout<<"ax^2 + bx + c "<<endl;
	cout<<"a�� �Է��Ͻÿ�: ";
	cin>>a;
	cout<<"b�� �Է��Ͻÿ�: ";
	cin>>b;
	cout<<"c�� �Է��Ͻÿ�: ";
	cin>>c;

	result1 = (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
	result2 = (-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);

	
	

	cout<<"������������ ���� "<<result1<<"�Ǵ� "<<result2<<"�Դϴ�."<<endl;
	
		

	return 0;
}