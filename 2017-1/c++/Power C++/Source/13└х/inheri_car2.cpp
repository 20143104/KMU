#include <iostream>
#include <string>
using namespace std;

class Car {	
public:
	int speed;
	int gear;
	string color;
	Car(): speed(0), gear(1), color("white") { }
	void setSpeed(int s){ speed = s; }
	int getSpeed(){ return speed; }
};

class SportsCar : public Car {	
public:
	int speed;
	int gear;
	string color;
	SportsCar(): speed(100), gear(3), color("blue") { }
};

int main()
{
	SportsCar sc;
	cout << "���ǵ�: " << sc.speed << endl;		// �ڽ� Ŭ������ speed
	cout << "���ǵ�: " << sc.Car::speed << endl;	// �θ� Ŭ������ speed
	cout << "���ǵ�: " << sc.getSpeed() << endl;	// �θ� Ŭ������ speed ��ȯ
	return 0;
}
