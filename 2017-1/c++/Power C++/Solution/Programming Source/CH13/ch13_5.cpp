#include <iostream>
#include <string>

using namespace std;

class Coffee {
private:
	int beans; 
	
public:
	Coffee()
	{
		cout<<"<Ŀ��>"<<endl;	
	}
	
};

class Latte : public Coffee{
private:
	int milk;
public:
	Latte() : Coffee()
	{
		cout<<"���Դϴ�."<<endl;	
	}
	
};

class Mocha : public Coffee{
private:
	int choco_syrup;
public:
	Mocha() : Coffee()
	{
		cout<<"��ī�Դϴ�."<<endl;
	}
	
};

class Cappuccino : public Coffee{
private:
	int milk_bubble;
public:
	Cappuccino() : Coffee()
	{
		cout<<"īǪġ���Դϴ�."<<endl;	
	}
	
};

class Americano : public Coffee{
private:
	int water;
public:
	Americano() : Coffee()
	{
		cout<<"�Ƹ޸�ī���Դϴ�."<<endl;	
	}
	
};

int main()
{
	Americano u1;
	Cappuccino u2;
	Latte u3;
	Mocha u4;
	
	return 0;
}
