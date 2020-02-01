#include <iostream>
#include <string>

using namespace std;

class Nation{
private:
	string country;
	double population;
	double area;
	double income;
public:
	Nation(){}
	Nation(string c, double p, double a, double i)
	{
		country = c;
		population = p;
		area = a;
		income = i;
	}
	void setCountry(string c)
	{
		country = c;
	}
	void setPopulation(double p)
	{
		population = p;
	}
	void setArea(double a)
	{
		area = a;
	}
	void setIncome(double i)
	{
		income = i;
	}
	string getCountry()
	{
		return country;
	}
	double getPopulation()
	{
		return population;
	}
	double getArea()
	{
		return area;
	}
	double getIncome()
	{
		return income;
	}
	void print()
	{
		cout<<"국가 이름 : "<<country<<endl;
		cout<<"인     구 : "<<population<<"만명"<<endl;
		cout<<"넓     이 : "<<area<<"㎢"<<endl;
		cout<<"국민 소득 : "<<income<<"$"<<endl;
	}
};

int main()
{
	double p1,p2,p3;
	Nation n1("대한민국",4977,100032,17074), n2("일본",12728,377835,39731), n3;
	n3.setCountry("중국");
	n3.setPopulation(133004);
	n3.setArea(9596960);
	n3.setIncome(3677);
	cout<<"========================================"<<endl;
	n1.print();
	n2.print();
	n3.print();
	cout<<"========================================"<<endl;
	cout<<"가장 인구가 많은 국가"<<endl;
	if(n1.getPopulation() < n2.getPopulation()){
		if(n2.getPopulation() > n3.getPopulation()){
			n2.print();
		}
		else{
			n3.print();
		}
	}
	else{
		if(n1.getPopulation() > n3.getPopulation()){
			n1.print();
		}
		else{
			n3.print();
		}
	}
	cout<<"========================================"<<endl;
	cout<<"가장 국민소득이 높은 국가"<<endl;
	if(n1.getIncome() < n2.getIncome()){
		if(n2.getIncome() > n3.getIncome()){
			n2.print();
		}
		else{
			n3.print();
		}
	}
	else{
		if(n1.getIncome() > n3.getIncome()){
			n1.print();
		}
		else{
			n3.print();
		}
	}
	return 0;	
}