#include <iostream>
using namespace std;
void swap(int &rx, int &ry);

int main()
{
	int a = 100, b = 200;
	cout << "swap() ȣ����: a = " << a << ", b = " << b << endl;
	swap(a, b);
	cout << "swap() ȣ����: a = " << a << ", b = " << b << endl;
	return 0;
}

void swap(int &rx, int &ry)
{
	int tmp;
	cout << "In swap() : rx = " << rx << ", ry = " << ry << endl;
	tmp = rx; rx = ry; ry = tmp;
	cout << "In swap() : rx = " << rx << ", ry = " << ry << endl;
}
