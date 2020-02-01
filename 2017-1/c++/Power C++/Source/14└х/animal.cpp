#include <iostream>
using namespace std;

class Animal 
{
public: 
	Animal() { cout <<"Animal ������" << endl; }
	~Animal() { cout <<"Animal �Ҹ���" << endl; }
	virtual void speak() { cout <<"Animal speak()" << endl; }
};

class Dog : public Animal 
{
public: 
	Dog() { cout <<"Dog ������" << endl; }
	~Dog() { cout <<"Dog �Ҹ���" << endl; }
	void speak() { cout <<"�۸�" << endl; }
};

class Cat : public Animal 
{
public: 
	Cat() { cout <<"Cat ������" << endl; }
	~Cat() { cout <<"Cat �Ҹ���" << endl; }
	void speak() { cout <<"�߿�" << endl; }
};

int main()
{
	Animal *a1 = new Dog();
	a1->speak();

	Animal *a2 = new Cat();
	a2->speak();
	return 0;
}
