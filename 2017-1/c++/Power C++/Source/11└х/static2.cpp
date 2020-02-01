#include <iostream>
#include <string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
	int id;        // �ڵ����� �ø��� ��ȣ

public:
	// ��üȭ�� Car ��ü�� ������ ���� ���� ����
	static int numberOfCars;	// ���� ������ ����
	Car(int s=0, int g=1, string c="white"): speed(s), gear(g), color(c) {
		// �ڵ����� ������ �����ϰ� id ��ȣ�� �Ҵ��Ѵ�.
		id = ++numberOfCars;
	}
	// ���� ��� �Լ� 
	static int getNumberOfCars() {
		return numberOfCars; // OK!
	}
};
int Car::numberOfCars=0;	// ���� ������ ����

int main()
{
	Car c1(100, 0, "blue"); 	// ù ��° ������ ȣ��
	Car c2(0, 0, "white"); 	// ù ��° ������ ȣ��
	int n = Car::getNumberOfCars();	// ���� ��� �Լ� ȣ��
	cout <<"���ݱ��� ������ �ڵ��� �� = " << n << endl;
	return 0;
}
