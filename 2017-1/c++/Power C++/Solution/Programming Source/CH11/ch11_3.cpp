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
	
	cout<<kilo<<"ų�ι��ʹ� "<<MyMetric::kiloToMile(kilo)<<" ���� �Դϴ�."<<endl;
	cout<<mile<<"������ "<<MyMetric::mileToKilo(mile)<<" ų�ι��� �Դϴ�."<<endl;
 
}