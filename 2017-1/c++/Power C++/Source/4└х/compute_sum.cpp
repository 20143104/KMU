#include <iostream>
using namespace std;

// �Լ� ����
int compute_sum(int n);

int main(void)
{
	int n, sum;

	cout << "������ �Է��Ͻÿ�: ";
	cin >> n;

	sum = compute_sum(n);		// �Լ� ���

	cout << "1���� " << n << "������ ���� " << sum << "�Դϴ�. \n";
}

// �Լ� ����
int compute_sum(int n)
{
	int i;
	int result = 0;

	for(i = 1; i <= n; i++)
		result += i;

	return result;
} 
