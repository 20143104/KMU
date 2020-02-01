#include <iostream>

using namespace std;

void get_input(int &x);
void get_input(int &x, int &y);

int main ()
{
	int n = 0, i = 0;
	int &x = n;
	int &y = i;
	get_input(x);
	cout<<x<<endl;
	get_input(x,y);
	cout<<x<<" "<<y<<endl;
	return 0;
}
void get_input(int &x)
{
	cout<<"정수를 입력하시오 : ";
	cin>>x;
}
void get_input(int &x, int &y)
{
	cout<<"정수를 입력하시오 : ";
	cin>>x>>y;
}