// �ּ� ������
#include <iostream>
using namespace std;

int main()
{
	int i = 10;
	char c = 69;
	double f = 12.3;

	cout << "i�� �ּ�: " << &i << endl;	// ���� i�� �ּ����
	cout << "c�� �ּ�: " << (void *)&c << endl;	// ���� c�� �ּ����
	cout << "f�� �ּ�: " << &f << endl;	// ���� f�� �ּ����

	return 0;
}
