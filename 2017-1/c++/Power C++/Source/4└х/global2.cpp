
// ���� ������ �ʱⰪ�� ���� �Ⱓ
#include <iostream>
using namespace std;

int counter;	// ���� ����

void set_counter(int i)
{
	counter = i;		// ���� ��� ����
}

int main(void)
{
	cout << "counter=" << counter << endl;	

	counter = 100;		// ���� ��� ����
	cout << "counter=" << counter << endl;	

	set_counter(20);		
	cout << "counter=" << counter << endl;	

	return 0;
}
