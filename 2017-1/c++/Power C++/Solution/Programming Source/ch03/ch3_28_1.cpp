#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int x, i = 1, fact = 1;
	cout<<"������ �Է��Ͻÿ�: ";
	cin>>x;
	cout<<"n\tn!"<<endl;
	cout<<"------------------------------"<<endl;

	for(i = 1;i <= x; i++){
		fact *= i;
		cout<<i<<"\t"<<fact<<endl;
	}
}
