#include <iostream>
#include <string>
using namespace std;
class Car
{
	string& alias;
	int speed;	// �ӵ� 
public:
	Car(string s) : alias(s) 
	{
		cout << alias << endl;
	}
};

int main()
{
	Car c1("���� �ڵ���");
	return 0;
}
