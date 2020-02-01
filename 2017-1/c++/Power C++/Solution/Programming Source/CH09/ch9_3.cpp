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
		cout<<"주사위의 숫자는 "<<D1.getFace()<<"입니다."<<endl;
	}
	return 0;
}
