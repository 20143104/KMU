#include <iostream>
#include <string>
using namespace std;

class Car {
	int speed; // �ӵ�
	int gear; // ���
	string color; // ����
public:
	// ù ��° ������
	Car(int s, int g, string c) {
		speed = s;
		gear = g;
		color = c;
	}
	void printInfo()
	{
		cout << "�ӵ�: " << speed << endl;
		cout << "���: " << gear << endl;
		cout << "����: " << color << endl;
	}
};
int main()
{
	Car c1(0, 1, "yellow");
	Car c2(c1);	// ���� ������ ȣ��

	c1.printInfo();
	c2.printInfo();
	return 0;
}
