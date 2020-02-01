#include <iostream>
#define PI 3.14159
using namespace std;
double cylinder(double r, double h = 1.0);

int main ()
{
	double r = 0, h = 0;

	
	cout<<"r = 4.0, h = 3.0 : "<<"v = "<<cylinder(4.0,3.0)<<endl;
	cout<<endl;
	cout<<"r = 4.0, h = default : "<<"v = "<<cylinder(4.0)<<endl;
	cout<<endl;
	return 0;
}
double cylinder(double r, double h)
{
	double v = 0;
	v = r*r*PI*h;
	return v;
}