#include <iostream>
using namespace std;

int calc_deposit(int salary=300, int month=12);

int main()
{
	cout << "0���� ����Ʈ �Ű� ���� ���"<< endl;
	cout << calc_deposit(200, 6) << endl;

	cout << "1���� ����Ʈ �Ű� ���� ���" << endl;
	cout << calc_deposit(200) << endl;

	cout << "2���� ����Ʈ �Ű� ���� ���" << endl;
	cout << calc_deposit() << endl;
	return 0;
}
	
int calc_deposit(int salary, int month)
{
	return salary*month;
}
