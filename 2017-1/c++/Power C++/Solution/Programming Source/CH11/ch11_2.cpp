#include <iostream>

using namespace std;

class MyMath
{
private:
	static double PI;
public:
	static double getPI()
	{
		return PI;
	}
};

double MyMath::PI = 3.1415192;

void main()
{
}