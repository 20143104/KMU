#include <iostream>

using namespace std;

void make_double(int &x);

int main ()
{
	int i = 0;
	int &x = i;
	
	cout<<"������ �Է��Ͻÿ� : ";
	cin>>x;
	make_double(x);
	cout<<"make_double : "<<x<<endl;
	return 0;
}

void make_double(int &x)
{
	x = 2*x;
}