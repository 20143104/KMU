#include <iostream>
#include <string>
using namespace std;
class Car {	
public:
	int getHP()	
	{		
		return 100;	// 100���� ��ȯ
	}
};
class SportsCar : public Car {	
public:

	int getHP()	
	{
		return 300;	// 300���� ��ȯ
	}
};
int main()
{
	SportsCar sc;
	cout << "����: " << sc.getHP() << endl;
	return 0;
}
