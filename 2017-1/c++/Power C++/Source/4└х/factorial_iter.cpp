// �ݺ����� ���丮�� �Լ� ���
#include <iostream>
using namespace std;
long factorial_iter(int n);

int main()
{
	int x;
	long f;

	cout << "������ �Է��Ͻÿ�: " ;
	cin >> x;

	f = factorial_iter(x);
	cout << x << "!�� " << f << "�Դϴ�. " << endl;

	return 0;
}

long factorial_iter(int n)
{
	long result;

	for(result = 1; n > 1; n--)
		result *= n;

	return result;
}
