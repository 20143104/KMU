#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	const int FACES=6;
	int freq[FACES] = { 0 };		// �ֻ����� ���� �󵵸� 0���� �Ѵ�.
	int i;
	
	for(i = 0; i < 10000; i++)		// �ֻ����� 10000�� ������.
		++freq[ rand() % FACES ];	// �ش���� �󵵸� �ϳ� �����Ѵ�.

	cout << "====================\n";
	cout << "��     ��\n";
	cout << "====================\n";

	for(i = 0; i < FACES; i++)
		cout << i << "         " << freq[i] << endl;
	
	return 0;
}
