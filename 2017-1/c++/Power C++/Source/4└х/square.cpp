#include <iostream>
using namespace std;

int square(int n);				// �Լ� ����

int main()
{
	int i, result;

	for(i = 0; i < 5; i++)
	{
		result = square(i);		// �Լ� ȣ��
		cout <<  result << endl;
	}

	return 0;
}

int square(int n)				// �Լ� ����
{
	return(n * n);
}
