#include <iostream>
using namespace std;	// �̸� ���� ����

int main()
{
	char ch = 'A';		// ���� ����
	int code = ch;
	
	cout <<  ch << "�� �ƽ�Ű �ڵ� = " << code << endl;

	ch = ch + 1;
	code = ch;
	cout <<  ch << "�� �ƽ�Ű �ڵ� = " << code << endl;;
	
	return 0;
}
