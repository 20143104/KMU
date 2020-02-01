#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	// ��� ���� ����
	int speed; // �ӵ�
	int gear; // ���
	string color; // ����

	// ��� �Լ� ����
	void speedUp() { // �ӵ� ���� ��� �Լ�
		speed += 10;
	}

	void speedDown() { // �ӵ� ���� ��� �Լ�
		speed -= 10;
	}
};

Car globalCar;			// �� ���� ��ü
int main()
{
	Car localCar;			// �� ���� ��ü
	Car *dynCar = new Car;	// �� ���� ��ü ����

	globalCar.speed = 100;;
	localCar.speed = 60;
	localCar.color = "white";
	dynCar->speed = 80;
	dynCar->speedUp();

	cout << "���� global ���� �ӵ��� " << globalCar.speed << endl;
	cout << "���� local ���� �ӵ��� " << localCar.speed << endl;
	cout << "���� dynamic ���� �ӵ��� " << dynCar->speed << endl;


	delete dynCar;		// ���� ��ü�� ����
	return 0;
}
