#include <iostream>
#include "car.h"		// ���� ��ġ�� car.h�� �о ������� ���� �ǹ��Ѵ�. 
using namespace std;

int main()
{
	Car myCar;
	myCar.setSpeed(80);
	myCar.honk();
	cout << "���� �ӵ��� " << myCar.getSpeed() << endl;
	return 0;
}
