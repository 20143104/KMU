#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
	string name;
	int age;
	int salary;
	int years;
public:
	void setEmployee(string n, int a, int s, int y){
		name = n;
		age = a;
		salary = s;
		years = y;
	}
	void setName(string u_name)
	{
		name = u_name;
	}
	void setAge(int u_age)
	{
		age = u_age;
	}
	void setSalary(int u_salary)
	{
		salary = u_salary;
	}
	void setYears(int u_years)
	{
		years = u_years;
	}
	string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	int getSalary()
	{
		return salary;
	}
	int getYears()
	{
		return years;
	}
};

int main()
{
	Employee e1;

	e1.setEmployee("홍길동", 26, 1000000, 1);
	cout<<"============================"<<endl;
	cout<<"이름 : "<<e1.getName()<<endl;
	cout<<"나이 : "<<e1.getAge()<<endl;
	cout<<"봉급 : "<<e1.getSalary()<<endl;
	cout<<"년도 : "<<e1.getYears()<<endl;
	cout<<"============================"<<endl;
}
