#include <iostream>
#include <string>
using namespace std;

class Car {
       int speed;
       int gear;
       string color;
 public:
       Car(int s=0, int g=1, string c="white") : speed(s), gear(g), color(c) {
       }
		void display();
};
void Car::display()
{
	cout << "�ӵ�: " << speed << " ���: " << gear << " ����: " << color << endl;
}

int main()
{
	Car myCar;			// ���� �޸� �Ҵ����� ��ü ����
	myCar.display();

	Car *pCar = &myCar;		// ��ü �����ͷ� ��ü�� ����Ű�� ��
	pCar->display();

	pCar = new Car(0, 1, "blue");		// ���� �޸� �Ҵ����� ��ü ����
	pCar->display();
	return 0;
}		
