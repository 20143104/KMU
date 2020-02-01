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
		cout<<"ȣ���� �׸��ϴ�."<<endl;
	}
};

class Titan : public GameCharacter
{
public:
	Titan() : GameCharacter(){}
	void draw()
	{
		cout<<"Ÿ��ź�� �׸��ϴ�."<<endl;
	}
};

class Magician : public GameCharacter
{
public:
	Magician() : GameCharacter(){}
	void draw()
	{
		cout<<"�ּ��縦 �׸��ϴ�."<<endl;
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