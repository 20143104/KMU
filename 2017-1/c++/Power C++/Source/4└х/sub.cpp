#include <iostream>
using namespace std;
static void f1()
{
	cout << "f1()�� ȣ��Ǿ����ϴ�.\n";
}

void f2()
{
	f1();
	cout << "f2()�� ȣ��Ǿ����ϴ�.\n";
}
