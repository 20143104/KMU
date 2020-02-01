#include <iostream>
#include <string>

using namespace std;

class Employee{
private:
	string name;
	int salary;
public:
	Employee(){
		name="Unknown"; 
		salary = 0;
	};
	Employee(string name, int salary)
	{
		this->name = name;
		this->salary = salary;
	}
	operator int() const
	{
		return salary;
	}
	void display()
	{
		cout<<"Name : "<<name<<endl;
		cout<<"Salary : "<<salary<<endl;	
	}
};
int main()
{
	Employee e("ȫ�浿", 100);
	int salary = (int) e; // salary�� 100�� ����ȴ�

	e.display();
	cout<<"int salary = "<<salary<<endl;

	return 0;
}