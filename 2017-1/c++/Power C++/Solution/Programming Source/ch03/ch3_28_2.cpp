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


    while(i <= x){
    fact *= i;
    cout<<i<<"\t"<<fact<<endl;
	i++;
	}
	return 0;
}
