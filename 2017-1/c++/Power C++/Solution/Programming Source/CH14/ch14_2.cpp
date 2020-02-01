#include <iostream>
#include <string>

using namespace std;

class HomeAppliance
{
private:
	double price;
public:
	HomeAppliance(double p)
	{
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
		cout<<"가 격 : "<<price<<endl;
	}
};

class Television : public HomeAppliance
{
private:
	string model;
	string maker;
public:
	Television(double p, string m, string mk) : HomeAppliance(p)
	{
		model = m;
		maker = mk;
	}
	
	void setModel(string m)
	{
		model = m;
	}
	void setMaker(string m)
	{
		maker = m;
	}
	string getModel()
	{
		return model;
	}
	string getMaker()
	{
		return maker;
	}
	void print()
	{	
		cout<<"======================"<<endl;
		cout<<"      Television"<<endl;
		cout<<"======================"<<endl;
		HomeAppliance::print();
		cout<<"모델명 : "<<model<<endl;
		cout<<"메이커 : "<<maker<<endl;
	}
};

class Refrigerator : public HomeAppliance
{
private:
	string model;
	string maker;
public:
	Refrigerator(double p, string m, string mk) : HomeAppliance(p)
	{
		model = m;
		maker = mk;
	}
	void setModel(string m)
	{
		model = m;
	}
	void setMaker(string m)
	{
		maker = m;
	}
	string getModel()
	{
		return model;
	}
	string getMaker()
	{
		return maker;
	}
	void print()
	{	
		cout<<"======================"<<endl;
		cout<<"     Refrigerator"<<endl;
		cout<<"======================"<<endl;
		HomeAppliance::print();
		cout<<"모델명 : "<<model<<endl;
		cout<<"메이커 : "<<maker<<endl;
	}
};

int main()
{
	Television t1(19000000,"72LEX9","LG");
	Television t2(9809000,"LN57F91BD","SAMSUNG");
	Refrigerator r1(4247000,"SRT746ZWKPZ","SAMSUNG");
	Refrigerator r2(2772000,"R-T758LHHSI","LG");
	t1.print();
	t2.print();
	r1.print();
	r2.print();
	return 0;
}

