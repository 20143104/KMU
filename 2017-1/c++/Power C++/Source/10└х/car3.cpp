#include <iostream>
#include <string>
using namespace std;

class Car {
private:
	int speed;		// �ӵ� 
	int gear;		// ���
	string color;	// ���� 
public:
	Car() 
	{
			cout << "����Ʈ ������ ȣ��" << endl;
		speed = 0;
		gear = 1;
		color = "white";
	}
	Car(int s, int g, string c) 
	{
			cout << "�Ű� ������ �ִ� ������ ȣ��" << endl;
		speed = s;
		gear = g;
		color = c;
	}
};
int main()
{
	Car c1; 		// ����Ʈ ������ ȣ��
	Car c2(100, 0, "blue"); // ������ ȣ��
	return 0;
}
