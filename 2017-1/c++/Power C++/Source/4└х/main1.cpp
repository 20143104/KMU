// ���� ���� ���� ����
#include <iostream>
using namespace std;
 
unsigned random_i(void);
double random_f(void);

extern unsigned call_count;	// �ܺ� ���� ����

int main()
{
	register int i;		// �������� ����
	
	for(i = 0; i < 10; i++)
		cout << random_i() << " ";

	cout << endl;

	for(i = 0; i < 10; i++)
		cout << random_f() << " ";

	cout << "\n�Լ��� ȣ��� Ƚ��= " << call_count;
	return 0;
}
