#include <iostream>
#include <string>
using namespace std;

class DeskLamp {
private:
	// �ν��Ͻ� ���� ����
	bool isOn;		// �����̳� ������ ���� ������ ����

public:
	// ��� �Լ� ����
	void turnOn();	// ������ �Ҵ�.
	void turnOff(); // ������ ����.
	void print();	// ���� ���¸� ���
};

void DeskLamp::turnOn()
{
	isOn = true;
}

void DeskLamp::turnOff()
{
	isOn = false;
}

void DeskLamp::print()
{
	cout << "������ " << (isOn == true ? "����" : "����") << endl;
}

int main() 
{
	// ��ü ����
	DeskLamp lamp;

	// ��ü�� ��� �Լ��� ȣ���Ϸ��� ��Ʈ �������� .�� ����Ѵ�.
	lamp.turnOn();
	lamp.print();
	lamp.turnOff();
	lamp.print();

	return 0;
}
