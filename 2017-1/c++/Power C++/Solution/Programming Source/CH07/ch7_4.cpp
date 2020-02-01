#include <iostream>

using namespace std;

void make_double(int &x);

int main ()
{
	int i = 0;
	int &x = i;
	
	cout<<"정수를 입력하시오 : ";
	cin>>x;
	make_double(x);
	cout<<"make_double : "<<x<<endl;
	return 0;
}

void make_double(int &x)
{
	x = 2*x;
}