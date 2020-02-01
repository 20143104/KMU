#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int x, i = 1, fact = 1;
	cout<<"정수를 입력하시오: ";
	cin>>x;
	cout<<"n\tn!"<<endl;
	cout<<"------------------------------"<<endl;

	for(i = 1;i <= x; i++){
		fact *= i;
		cout<<i<<"\t"<<fact<<endl;
	}
}
