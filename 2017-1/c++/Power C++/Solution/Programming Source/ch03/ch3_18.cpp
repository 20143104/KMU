#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a = 0.0, b = 0.0, c = 0.0, tmp = 0.0;
	double root = 0.0, root1 = 0.0;

	cout<<"방정식의 계수 a,b,c를 입력 하세요 : ";
	cin>>a>>b>>c;

	if( a == 0 ){
		root = -c/b;
		cout<<"방정식의 근은 : "<<root<<endl;
	}
	else{
		tmp = sqrt( pow(b,2)-(4*a*c) );
		if( tmp < 0)
			cout<<"실근을 존재하지 않습니다."<<endl;
		else{
			root  = (-b + tmp)/ (2*a);
			root1 = (-b - tmp)/ (2*a);
			cout<<"실근은 : "<<root<<", "<<root1<<endl;
		}
	}
	return 0;
}
