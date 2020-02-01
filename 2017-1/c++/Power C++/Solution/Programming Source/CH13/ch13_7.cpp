#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string name;
	string snum;
	string major;
	int grade;
	int credit;
public:
	Student(string n, string sn, string m, int g, int c)
	{
		name = n;
		snum = sn;
		major = m;
		grade = g;
		credit = c;
	}
	void setName(string n)
	{
		name = n;
	}
	void setSnum(string sn)
	{
		snum = sn;
	}
	void setMajor(string m)
	{
		major = m;
	}
	void setGrade(int g)
	{
		grade = g;
	}
	void setCredit(int c)
	{
		credit = c;
	}
	string getName()
	{
		return name;
	}
	string getSnum()
	{
		return snum;
	}
	string getMajor()
	{
		return major;
	}
	int getGrade()
	{
		return grade;
	}
	int getCredit()
	{
		return credit;
	}
	void print()
	{
		cout<<"��    �� : "<<name<<endl;
		cout<<"��    �� : "<<snum<<endl;
		cout<<"�Ҽ��а� : "<<major<<endl;
		cout<<"��    �� : "<<grade<<endl;
		cout<<"�̼����� : "<<credit<<endl;
	}
};

class UnderGraduate : public Student{
private:
	string club;
public:
	UnderGraduate(string n, string sn, string m, int g, int c, string club) : Student( n, sn, m, g, c)
	{
		this->club = club;
	}
	void setClub(string c)
	{
		club = c;
	}
	string getClub()
	{
		return club;
	}
	void print()
	{
		Student::print();
		cout<<"���Ƹ��� : "<<club<<endl;
	}
};

class Graduate : public Student{
private:
	string assistant;
	double srate;
public:
	Graduate(string n, string sn, string m, int g, int c, string as, double sr) : Student( n, sn, m, g, c)
	{
		assistant = as;
		srate = sr;
	}
	void print()
	{
		Student::print();
		cout<<"�������� : "<<assistant<<endl;
		cout<<"���к��� : "<<srate<<endl;
	}
};

int main()
{
	Graduate g("ȫ�浿","20051111","��ǻ�Ͱ��а�",4, 140,"��������", 0.5);
	UnderGraduate u("�ϱ浿","20011111","��ǻ�Ͱ��а�",2, 80,"Visaul C++");

	g.print();
	cout<<"-------------------------"<<endl;
	u.print();
	return 0;
}
