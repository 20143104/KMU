#include <iostream>

using namespace std;
int main()
{
	double x = 0.0, f = 0.0;
	
	cout<<"x���� �Է��ϼ��� : ";
	cin>>x;

	if( x<= 0)
		f= (x*x*x)-(9*x)+2;
	else if( x >0 )
		f= (7*x)+(2*x)+0;

	cout<<"f(x) �� ���� : "<<f<<endl;

	return 0;
}
