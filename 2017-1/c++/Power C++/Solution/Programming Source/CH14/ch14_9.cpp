#include <iostream>
#include <string>

using namespace std;

class GameCharacter
{
public:
	virtual void draw(){}
};

class Hobit : public GameCharacter
{
public:
	Hobit() : GameCharacter(){}
	void draw()
	{
		cout<<"호빗을 그립니다."<<endl;
	}
};

class Titan : public GameCharacter
{
public:
	Titan() : GameCharacter(){}
	void draw()
	{
		cout<<"타이탄을 그립니다."<<endl;
	}
};

class Magician : public GameCharacter
{
public:
	Magician() : GameCharacter(){}
	void draw()
	{
		cout<<"주술사를 그립니다."<<endl;
	}
};

int main(void)
{
	GameCharacter *ac[3];
	ac[0] = new Hobit();
	ac[1] = new Titan();
	ac[2] = new Magician();

	for(int i = 0; i < 3 ; i++){
		cout<<"======================"<<endl;
		ac[i]->draw();
		cout<<"======================"<<endl;
	}
	
	return 0;
}