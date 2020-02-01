#include <iostream>
#define PI 3.14159
using namespace std;
inline double calc_area(double r)
{
	double area = 0;

	area = r*r*PI;
	return area;
}

int main ()
{
	double r = 0, area = 0;
	
	cout<<"원의 반지름을 입력하시오 : ";
	cin>>r;
	area = calc_area(r);
	cout<<"원의 넓이는 : "<<area<<endl;
	return 0;
}