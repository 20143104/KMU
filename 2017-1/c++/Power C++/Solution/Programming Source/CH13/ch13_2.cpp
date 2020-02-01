#include <iostream>
#include <string>

using namespace std;

class Person{
private:
	string name;
	string loc;
	string pnumber;
public:
	Person(string n, string l, string pn)
	{
		name = n;
		loc = l;
		pnumber = pn;
	}
	void setName(string n)
	{
		name = n;
	}
	void setLoc(string l)
	{
		loc = l;
	}
	void setPnumber(string pn)
	{
		pnumber = pn;
	}
	string getName()
	{
		return name;
	}
	string getLoc()
	{
		return loc;
	}
	string getPnumber()
	{
		return pnumber;
	}
};

class Customer : public Person{
private:
	int cnum;
	int mileage;
public:
	Customer(string n, string l, string pn, int cn) : Person(n, l, pn)
	{
		cnum = cn;
	}
	void setCnum(int cn)
	{
		cnum = cn;
	}
	void setMileage(int m)
	{
		mileage = m;
	}
	int getCnum()
	{
		return cnum;
	}
	int getMileage()
	{
		return mileage;
	}
	
};

int main()
{
	
	return 0;	
}
