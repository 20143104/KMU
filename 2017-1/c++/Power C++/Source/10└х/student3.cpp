#include <iostream>
#include <string>
using namespace std;

class Student {
	char *name; // �̸�
	int number;
public:
	// ù ��° ������
	Student(char *pn, int n) {
		name = new char[strlen(pn)+1];
		strcpy(name, pn);
		number = n;
	}
	Student(Student& s) {
		name = new char[strlen(s.name)+1];
		strcpy(name, s.name);
		number = s.number;
	}

	~Student() {
		delete [] name;
	}
	void setName(char *pn)
	{
		delete[] name;
		name = new char[strlen(pn)+1];
		strcpy(name, pn);
	}
	void setNumber(int n)
	{
		number = n;
	}
	int getNumber()
	{
		return number;
	}
	void printInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "�й�: " << number << endl;
	}

};
Student modifyNumber(Student obj)
{
	obj.setNumber(obj.getNumber() + 1);
	return obj;
}
int main()
{
	Student s1("Park", 20100001);
	Student s2 = modifyNumber(s1);
	s1.printInfo();
	s2.printInfo();
	return 0;
}
