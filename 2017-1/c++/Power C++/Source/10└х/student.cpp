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
	~Student() {
		delete [] name;
	}
	void setName(char *pn)
	{
		delete[] name;
		name = new char[strlen(pn)+1];
		strcpy(name, pn);
	}
	void printInfo()
	{
		cout << "�̸�: " << name << " ";
		cout << "�й�: " << number << endl;
	}
};
int main()
{
	Student s1("Park", 20100001);
	Student s2(s1);	// ���� ������ ȣ��

	s1.printInfo();
	s2.printInfo();
	s1.setName("Kim");

	s1.printInfo();
	s2.printInfo();
	return 0;
