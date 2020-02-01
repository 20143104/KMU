#include <iostream>

using namespace std;

class MyMetric
{
public:
	static double kiloToMile(double k)
	{
		return k * 1.609347;
	}
	static double mileToKilo(double m)
	{
		return m * 0.6214;
	}
};

void main()
{
	double kilo = 0.71234;
	double mile = 3.24242;
	
	cout<<kilo<<"킬로미터는 "<<MyMetric::kiloToMile(kilo)<<" 마일 입니다."<<endl;
	cout<<mile<<"마일은 "<<MyMetric::mileToKilo(mile)<<" 킬로미터 입니다."<<endl;
 
}