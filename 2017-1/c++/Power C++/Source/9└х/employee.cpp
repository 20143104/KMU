#include <iostream>
#include <string>
using namespace std;
class Employee {
	string name;	// private �� ����
	int salary;	// private �� ����
	int age;		// private �� ����
	// ������ ������ ��ȯ
	int getSalary() {	return salary;	}
public:
	// ������ ���̸� ��ȯ
	int getAge() {	return age;	}
	// ������ �̸��� ��ȯ
	string getName() {    return name;	}
};

int main()
{
	Employee e;
	e.salary = 300; 	// ����! private ����
	e.age = 26; 	// ����! private ����
	int sa = e.getSalary();	// ����! private ��� �Լ�
	string s = e.getName(); // OK!
	int a = e.getAge();	// OK
}
