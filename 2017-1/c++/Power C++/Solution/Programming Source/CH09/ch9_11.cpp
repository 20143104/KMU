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
		cout<<"��ǰ �̸� : "<<name<<endl;
		cout<<"��     �� : "<<price<<endl;
		cout<<"��     �� : "<<assessment<<endl;
	}

private:
	string name;
	double price;
	string assessment;
};

int main()
{
	Product p1,p2;
	p1.getInfo("i7 870(���ʵ�)",324000,"2.93GHz");
	p2.getInfo("i5 760(���ʵ�)",208000,"2.8GHz");
	p1.isBetter(p2);
	p1.print();
	p2.print();
	return 0;
}
