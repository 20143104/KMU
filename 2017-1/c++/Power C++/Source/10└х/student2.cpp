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
	char *getName()
	{
		return name;
	}
	int getNumber()
	{
		return number;
	}
};
void displayStudent(Student obj)
{
	cout << "�̸�: " << obj.getName() << endl;
	cout << "�й�: " << obj.getNumber() << endl;
}

int main()
{
	Student s1("Park", 20100001);
	displayStudent(s1);
	return 0;
}
