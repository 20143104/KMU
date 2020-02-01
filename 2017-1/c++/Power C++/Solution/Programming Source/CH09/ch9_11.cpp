#include <iostream>
#include <string>

using namespace std;

class Product{
public:
	void getInfo(string name, double price, string assessment)
	{
		this->name = name;
		this->price = price;
		this->assessment = assessment;
	}
	bool isBetter(Product another)
	{
		return true;
	}
	void print()
	{
		cout<<"제품 이름 : "<<name<<endl;
		cout<<"가     격 : "<<price<<endl;
		cout<<"평     가 : "<<assessment<<endl;
	}

private:
	string name;
	double price;
	string assessment;
};

int main()
{
	Product p1,p2;
	p1.getInfo("i7 870(린필드)",324000,"2.93GHz");
	p2.getInfo("i5 760(린필드)",208000,"2.8GHz");
	p1.isBetter(p2);
	p1.print();
	p2.print();
	return 0;
}
