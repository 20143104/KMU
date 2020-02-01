#include <iostream>
#include <string>

using namespace std;

class Coffee {
private:
	int beans; 
	
public:
	Coffee()
	{
		cout<<"<커피>"<<endl;	
	}
	
};

class Latte : public Coffee{
private:
	int milk;
public:
	Latte() : Coffee()
	{
		cout<<"라떼입니다."<<endl;	
	}
	
};

class Mocha : public Coffee{
private:
	int choco_syrup;
public:
	Mocha() : Coffee()
	{
		cout<<"모카입니다."<<endl;
	}
	
};

class Cappuccino : public Coffee{
private:
	int milk_bubble;
public:
	Cappuccino() : Coffee()
	{
		cout<<"카푸치노입니다."<<endl;	
	}
	
};

class Americano : public Coffee{
private:
	int water;
public:
	Americano() : Coffee()
	{
		cout<<"아메리카노입니다."<<endl;	
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
