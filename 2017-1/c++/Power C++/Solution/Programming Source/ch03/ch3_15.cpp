#include <iostream>

using namespace std;
int main()
{
	double x = 0.0, f = 0.0;
	
	cout<<"x값을 입력하세요 : ";
	cin>>x;

	if( x<= 0)
		f= (x*x*x)-(9*x)+2;
	else if( x >0 )
		f= (7*x)+(2*x)+0;

	cout<<"f(x) 의 값은 : "<<f<<endl;

	return 0;
}
