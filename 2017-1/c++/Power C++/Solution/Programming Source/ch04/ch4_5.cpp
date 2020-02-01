#include <iostream>
#include <cmath>

using namespace std;

#define E 0.00001

double NewtonRaphson(double);

int main()
{
	int n = 0;
	cout<<"제곱근을 구할 정수를 입력하시오: ";
	cin>>n;

	cout<<n<<"의 제곱근 근사치는 "<<NewtonRaphson(n)<<"입니다."<<endl;	
	return 0;
}

double NewtonRaphson(double n)
{
	double r = 1;
	while(1){
		if(abs(r*r-n) < E){
			return r;
		}
		else{
			r = (n/r + r)/2;
		}
	}
	
}