#include <iostream>
#include <string>

using namespace std;

double getAverage(int, int);
double getAverage(int, int, int);

int main()
{
	int a = 0,b = 0,c = 0;
	
	cout<<"정수를 입력하시오 : ";
	cin>>a;
	cout<<"정수를 입력하시오 : ";
	cin>>b;
	cout<<"평균 : "<<getAverage(a,b)<<endl;
	
	return 0;
}

double getAverage(int a, int b)
{
	return (a+b)/2;
}
double getAverage(int a, int b, int c)
{
	return (a+b+c)/3;
}