// ���� ����
#include <iostream>
using namespace std;

int x = 123;	// ���� ����

void sub1()
{
	cout << "In sub1()  x=" << x << endl;	// ���� ���� x ����
}
	
void sub2()
{
	cout << "In sub2()  x=" << x << endl;	// ���� ���� x ����
}

int main(void)
{
	sub1();
	sub2();

	return 0;
}
