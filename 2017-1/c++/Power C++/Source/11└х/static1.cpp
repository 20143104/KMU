#include <iostream>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
	int id;        // �ڵ����� �ø��� ��ȣ

public:
	// ��üȭ�� Car ��ü�� ������ ���� ���� ����
	static int numberOfCars;
	Car(int s=0, int g=1, string c="white"): speed(s), gear(g), color(c) {
		// �ڵ����� ������ �����ϰ� id ��ȣ�� �Ҵ��Ѵ�.
		id = ++numberOfCars;
	}
};
int Car::numberOfCars = 0;

int main()
{
	Car c1;
	cout << Car::numberOfCars << endl;

	Car c2;
	cout << c2.numberOfCars << endl;
}
