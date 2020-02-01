#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	// 3���� ��� ���� ����
	int speed; // �ӵ�
	int gear; // ����Ÿ�
	string color; // ����

	// 3���� ��� �Լ� ���� 
	void setGear(int newGear) { // ��� ���� ��� �Լ�
		gear = newGear;
	}
	void speedUp(int increment) { // �ӵ� ���� ��� �Լ�
		speed += increment;
	}
	void speedDown(int decrement) { // �ӵ� ���� ��� �Լ�
		speed -= decrement;
	}
};

// Car Ŭ������ ��ӹ޾Ƽ� ������ ���� SportsCar Ŭ������ �ۼ��Ͽ� ����. 
class SportsCar : public Car {		// Car�� ��ӹ޴´�.
	// 1���� ��� ������ �߰�
    bool turbo;	
 
public: 	
	// 1���� ��� �Լ��� �߰�
	void setTurbo(bool newValue) { // �ͺ� ��� ���� ��� �Լ�
		turbo = newValue;
	}
};
