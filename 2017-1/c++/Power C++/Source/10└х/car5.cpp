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
	// ���� �־��� ������
	Car(string c) {
		Car(0, 0, c);		// ù ��° �����ڸ� ȣ���Ѵ�. 
	}
};

int main()
{
	Car c1("white");
	return 0;
}
