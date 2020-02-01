#include <iostream>
#include <cmath>

using namespace std;

#define E 0.00001

double NewtonRaphson(double);

int main()
{
	int n = 0;
	cout<<"�������� ���� ������ �Է��Ͻÿ�: ";
	cin>>n;

	cout<<n<<"�� ������ �ٻ�ġ�� "<<NewtonRaphson(n)<<"�Դϴ�."<<endl;	
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