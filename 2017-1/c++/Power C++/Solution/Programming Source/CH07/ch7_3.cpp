#include <iostream>

using namespace std;

int get_max(int x, int y);
double get_max(double x, double y);

int main ()
{
	int sel = 0;
	int x = 0, y = 0;
	double n = 0, i = 0;
	cout<<"1. ����"<<endl;
	cout<<"2. �Ǽ�"<<endl;
	cout<<">>";
	cin>>sel;
	if(sel == 1){
		cout<<"�� �� �� ������ �Է��Ͻÿ� : ";
		cin>>x>>y;
		cout<<"�ִ밪 : "<<get_max(x,y)<<endl;
	}
	else if(sel == 2){
		cout<<"�� �� �� �Ǽ��� �Է��Ͻÿ� : ";
		cin>>n>>i;
		cout<<"�ִ밪 : "<<get_max(n,i)<<endl;
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