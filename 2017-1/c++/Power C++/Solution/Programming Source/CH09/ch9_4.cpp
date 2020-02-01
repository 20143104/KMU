#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
	string name;
	string number;
	int salary;
public:
	void setEmployee(string name, string number, int salary)
	{
		this->name = name; // 앞에 this->name은 멤버변수를 뜻한다.
		this->number = number;
		this->salary = salary;
	}
	int getSalary()
	{
		return salary;
	}
	string getName()
	{
		return name;
	}
	string getNumber()
	{
		return number;
	}
};

int main()
{
	Employee emp1;

	emp1.setEmployee("홍길동","010-1234-5678",40000000);
	
	cout<<"이름 : "<<emp1.getName()<<", 전화번호 : "<<emp1.getNumber()<<", 연봉 : "<<emp1.getSalary()<<"원"<<endl;
	return 0;
}