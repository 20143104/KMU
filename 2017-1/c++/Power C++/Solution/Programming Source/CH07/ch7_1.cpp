#include <iostream>

using namespace std;

void get_input(int &x);

int main ()
{
	int n = 0;
	int &x = n;
	get_input(x);
	cout<<x<<endl;
	return 0;
}
void get_input(int &x)
{
	cout<<"������ �Է��Ͻÿ� : ";
	cin>>x;
}
