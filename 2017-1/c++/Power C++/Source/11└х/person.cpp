#include <iostream>
#include <string>
using namespace std;

class Person {
	string lastName;
	string firstName;
public:
	Person(string lastName, string firstName);
	string getLastName() {
		return lastName;
	};
	string getFirstName() {
		return firstName;
	}
	string buildName();
};
Person::Person(string lastName, string firstName) 
{
	this->lastName = lastName; 	// this�� ���� ��ü�� ����Ų��.
	this->firstName = firstName; 	// this�� ���� ��ü�� ����Ų��.
} 
string Person::buildName() {
	return this->getLastName() + this->getFirstName();	// ��
} 
int main()
{
	Person person("ȫ", "�浿");
	cout << person.buildName() << endl;
}
