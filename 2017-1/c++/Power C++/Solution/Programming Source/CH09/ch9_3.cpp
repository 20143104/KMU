#include <iostream>
#include <ctime>

using namespace std;

class Dice
{
private:
	int face;
public:
	void roll()
	{
		face = (int)(rand()%6+1);
	}
	int getFace()
	{
		return face;
	}
};

int main()
{
	Dice D1;
	srand(time(NULL));
	for(int i = 0; i < 10; i++){
		D1.roll();
		cout<<"�ֻ����� ���ڴ� "<<D1.getFace()<<"�Դϴ�."<<endl;
	}
	return 0;
}
