#include <iostream>
using namespace std;

// �������� �����ϴ� �Լ�
inline double square(double i)
{
	return i*i;
}
int main()
{
	double result;

	cout << "2.0�� ������ ";
	result = square(2.0);
	cout << result << endl;
	cout << "3.0�� ������ ";
	result = square(3.0);
	cout << result << endl;
	return 0;
}
