#include <iostream>

using namespace std;

int get_max(int x, int y);
double get_max(double x, double y);

int main ()
{
	int sel = 0;
	int x = 0, y = 0;
	double n = 0, i = 0;
	cout<<"1. 정수"<<endl;
	cout<<"2. 실수"<<endl;
	cout<<">>";
	cin>>sel;
	if(sel == 1){
		cout<<"비교 할 두 정수를 입력하시오 : ";
		cin>>x>>y;
		cout<<"최대값 : "<<get_max(x,y)<<endl;
	}
	else if(sel == 2){
		cout<<"비교 할 두 실수를 입력하시오 : ";
		cin>>n>>i;
		cout<<"최대값 : "<<get_max(n,i)<<endl;
	}
	return 0;
}
int get_max(int x, int y)
{
	if(x > y){
		return x;
	}
	else {
		return y;
	}
}
double get_max(double x, double y)
{
	if(x > y){
		return x;
	}
	else {
		return y;
	}
}