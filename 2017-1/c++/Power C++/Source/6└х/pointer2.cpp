#include <iostream>
using namespace std;

int main()
{
	char c = 'A';		// ������ ���� ����
	int i = 10000;	// ������ ���� ����
	double d = 6.78;	// �Ǽ��� ���� ����

	char *pc = &c;	// ������ ������ ���� �� �ʱ�ȭ
	int *pi = &i;         // ������ ������ ���� �� �ʱ�ȭ
	double *pd = &d;     // �Ǽ��� ������ ���� �� �ʱ�ȭ

	(*pc)++;		// ���� ������ 1 ����
	*pi = *pi + 1;	// ���� ������ 1 ����
	*pd += 1;		// ���� ������ 1 ����

	cout << c << endl;
	cout << i << endl;
	cout << d << endl;
		
	return 0;
}
