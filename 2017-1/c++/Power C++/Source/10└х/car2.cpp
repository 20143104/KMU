#include <iostream>
#include <string>
using namespace std;

class Car {
private:
	int speed;		// �ӵ� 
	int gear;		// ���
	string color;		// ���� 

public:
	Car(int s, int g, string c) 
	{
		speed = s;
		gear = g;
		color = c;
	}
	void printInfo();
};
void Car::printInfo()
{
	cout << "�ӵ�: " << speed << endl;
	cout << "���: " << gear << endl;
	cout << "����: " << color << endl;
}

int main()
{
	Car c1(0, 1, "red"); 	  	// ������ ȣ��
	Car c2 = Car(0, 1, "blue"); 	// �̷� �����ε� ������ ȣ���� �����ϴ�. 
	c1.print();
	c2.print();
	return 0;
}
