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
		this->name = name; // �տ� this->name�� ��������� ���Ѵ�.
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

	emp1.setEmployee("ȫ�浿","010-1234-5678",40000000);
	
	cout<<"�̸� : "<<emp1.getName()<<", ��ȭ��ȣ : "<<emp1.getNumber()<<", ���� : "<<emp1.getSalary()<<"��"<<endl;
	return 0;
}