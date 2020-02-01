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
		cout<<"이    름 : "<<name<<endl;
		cout<<"학    번 : "<<snum<<endl;
		cout<<"소속학과 : "<<major<<endl;
		cout<<"학    년 : "<<grade<<endl;
		cout<<"이수학점 : "<<credit<<endl;
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
		cout<<"동아리명 : "<<club<<endl;
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
		cout<<"조교유형 : "<<assistant<<endl;
		cout<<"장학비율 : "<<srate<<endl;
	}
};

int main()
{
	Graduate g("홍길동","20051111","컴퓨터공학과",4, 140,"연구조교", 0.5);
	UnderGraduate u("하길동","20011111","컴퓨터공학과",2, 80,"Visaul C++");

	g.print();
	cout<<"-------------------------"<<endl;
	u.print();
	return 0;
}
