#include <iostream>
#include <string>
using namespace std;

// �л��� ��Ÿ����. 
class Student {
private:
	string name;
	string telephone;
public:
	Student(const string n="", const string t="");
	string getTelephone() const;
	void setTelephone(const string t);
	string getName() const;
	void setName(const string n);
};

Student::Student(const string n, const string t)
{
	name = n;
	telephone = t;
}

string Student::getTelephone() const
{
		return telephone;
}
void Student::setTelephone(const string t)
{
		telephone = t;
}

string Student::getName() const
{
		return name;
}
void Student::setName(const string n)
{
		name = n;
}

// �������� ��Ÿ����. 
class Lab {
       string name;
	   Student *chief;
	   Student *manager;
public:
	Lab(string n="");
	void setChief(Student *p);
	void setManager(Student *p);
	void print() const;
};

Lab::	Lab(const string n)
{
	name = n;
	chief = NULL;
	manager = NULL;
}

void Lab::setChief(Student *p)
{
	chief = p;
}

void Lab::setManager(Student *p)
{
		manager = p;
}
	
void Lab::print() const
{
	cout << name << "������" << endl;
	if( chief != NULL )
		cout << "������ " << chief->getName() << endl;
	else 
		cout << "������ ���� �����ϴ�\n";
	if( manager != NULL )
		cout << "�ѹ��� " << manager->getName() << endl;
	else 
		cout << "�ѹ��� ���� �����ϴ�\n";
}

int main()
{
	Lab lab("���� ó��");
	Student *p= new Student("��ö��", "011-123-5678");

	lab.setChief(p);
	lab.setManager(p);
	lab.print();

	delete p;
	return 0;
}		
