#include <iostream>

using namespace std;
void get_divisor(int n);

int main()
{
	int n = 0;

	cout<<"������ �Է��Ͻÿ�: ";
	cin>>n;

	get_divisor(n);
	cout<<endl;

	return 0;
}
void get_divisor(int n)
{
	int i;
	for(i = 1;i <= n; i++){
		if(n%i == 0){
			cout<<i<<" ";
		}
	}
}