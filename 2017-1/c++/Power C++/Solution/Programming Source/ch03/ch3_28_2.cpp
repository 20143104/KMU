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


    while(i <= x){
    fact *= i;
    cout<<i<<"\t"<<fact<<endl;
	i++;
	}
	return 0;
}
