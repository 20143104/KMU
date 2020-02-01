#include <iostream>
#include <string>

using namespace std;

class Product 
{
protected:
	string name;
	double price;
public:
	Product(string n, double p)
	{
		name = n;
		price = p;
	}
	void setPrice(double p)
	{
		price = p;
	}
	virtual double getPrice()
	{
		return price;
	}
	void print()
	{
		cout<<"��ǰ�� : "<<name<<endl;
		cout<<"��  �� : "<<price<<endl;
	}
	
};

class DiscountProduct : public Product
{
private:
	double discount;
public:
	DiscountProduct(string n, double p, double d) : Product(n,p)
	{
		discount = d;
	}
	double getPrice()
	{
		return price-(price*(discount/100));
	}
	void print()
	{
		Product::print();
		cout<<"������ : "<<discount<<endl;
	}
};

int main(void)
{
	Product *p1 = new Product("toothbrush",3000);
	Product *p2 = new DiscountProduct("toothbrush",3000,15);

	cout<<p1->getPrice()<<endl;
	cout<<p2->getPrice()<<endl;

	return 0;
}