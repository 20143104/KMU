#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a = 0.0, b = 0.0, c = 0.0, tmp = 0.0;
	double root = 0.0, root1 = 0.0;

	cout<<"�������� ��� a,b,c�� �Է� �ϼ��� : ";
	cin>>a>>b>>c;

	if( a == 0 ){
		root = -c/b;
		cout<<"�������� ���� : "<<root<<endl;
	}
	else{
		tmp = sqrt( pow(b,2)-(4*a*c) );
		if( tmp < 0)
			cout<<"�Ǳ��� �������� �ʽ��ϴ�."<<endl;
		else{
			root  = (-b + tmp)/ (2*a);
			root1 = (-b - tmp)/ (2*a);
			cout<<"�Ǳ��� : "<<root<<", "<<root1<<endl;
		}
	}
	return 0;
}
