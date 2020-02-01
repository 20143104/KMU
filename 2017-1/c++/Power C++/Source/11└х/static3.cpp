#include <iostream>
#include <string>
using namespace std;

class Employee {
	string name;
	double salary;

	static int count; 	// ���� ����
public:
	// ������ 
	Employee(string n="", double s=0.0): name(n), salary(s) {
		count++; // ���� ������ count�� ����
	} 

	// ��ü�� �Ҹ�� �� ȣ��ȴ�. 
	~Employee() {
		count--; // ������ �ϳ� �پ��� ���̹Ƿ� count�� �ϳ� ����
	} 

	// ���� ��� �Լ�
	static int getCount() {
		return count;
	} 
};
int Employee::count=0; 	// ���� ����

int main()
{
	Employee e1("��ö��", 35000);
	Employee e2("�ּ�ö", 50000);
	Employee e3("��öȣ", 20000);

	int n = Employee::getCount();
	cout << "������ ������=" << n << endl;
	return 0;
}
