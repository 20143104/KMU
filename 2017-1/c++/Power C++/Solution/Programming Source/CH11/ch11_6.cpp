#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(){}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	~Date(){ }
	int getY() { return year; }
	int getM() { return month; }
	int getD() { return day; }
	void setY(int y) { year = y; }
	void setM(int m) { month = m; }
	void setD(int d) { day = d; }
	void print()
	{
		cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
	}
};

class Employee
{
private:
	string name;
	Date birthDate;
	Date hireDate;
public:
	Employee(string name, Date& birthDate, Date& hireDate)
	{
		this->name = name;
		this->birthDate = birthDate;
		this->hireDate = hireDate;
	}
	void print()
	{
		cout<<"������ �̸� : "<<name<<endl;
		cout<<"������ ���� : ";
		birthDate.print();
		cout<<"������ �Ի��� : ";
		hireDate.print();
	}
};

void main()
{
	Date bir(1987,4,27);
	Date hir(2011,2,05);
	Employee emp("ȫ�浿", bir, hir);

	emp.print();
}

