#include <iostream>
using namespace std;

const int CLASSES=3;
const int STUDENTS=5;

int main()
{
	int s[CLASSES][STUDENTS] = {
		{  0,  1,  2,  3,  4 },	// ù��° ���� ���ҵ��� �ʱⰪ
		{ 10, 11, 12, 13, 14 },	// �ι�° ���� ���ҵ��� �ʱⰪ
		{ 20, 21, 22, 23, 24 },	// ����° ���� ���ҵ��� �ʱⰪ
	};
	int clas, student, total, subtotal;
	
	total = 0;
	for(clas = 0; clas < CLASSES; clas++)
	{
		subtotal = 0;
		for(student = 0; student < STUDENTS; student++)
			subtotal += s[clas][student];
		cout << "�б� " << clas << "�� ��� ����= " << subtotal / STUDENTS << endl;
		total += subtotal;
	}
	
	cout << "��ü �л����� ��� ����= " << total/(CLASSES * STUDENTS) << endl;
	
	return 0;
}
