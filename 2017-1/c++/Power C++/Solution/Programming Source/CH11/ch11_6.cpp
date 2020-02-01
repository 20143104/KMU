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
		cout<<year<<"년"<<month<<"원"<<day<<"일"<<endl;
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
		cout<<"직원의 이름 : "<<name<<endl;
		cout<<"직원의 생일 : ";
		birthDate.print();
		cout<<"직원의 입사일 : ";
		hireDate.print();
	}
};

void main()
{
	Date bir(1987,4,27);
	Date hir(2011,2,05);
	Employee emp("홍길동", bir, hir);

	emp.print();
}

