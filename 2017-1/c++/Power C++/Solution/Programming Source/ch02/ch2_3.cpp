#include <iostream>

using namespace std;

int main()
{
	double x = 0;

	x = (3.32 * 1e-3 * 9.76 * 1e-8)/(9.12 * 1e6 * 9.76 + 1e9);

	cout<<x<<endl;

	return 0;
}