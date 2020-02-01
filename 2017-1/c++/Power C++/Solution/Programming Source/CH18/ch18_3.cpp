#include <iostream>
#include <list>
#include <string>

using namespace std;

class Student
{
private:
	string name;
	string ad;
	int snum;
	string pnum;
public:
	Student(string n, string a, int s, string p)
	{
		name = n;
		ad = a;
		snum = s;
		pnum = p;
	}
	void setName(string n)
	{
		name = n;
	}
	void setAd(string a)
	{
		ad = a;
	}
	void setSnum(int s)
	{
		snum = s;
	}
	void setPnum(string p)
	{
		pnum = p;
	}
	string getName()
	{
		return name;
	}
	string getAd()
	{
		return ad;
	}
	int getSnum()
	{
		return snum;
	}
	string getPnum()
	{
		return pnum;
	}
	void print()
	{
		cout<<"학생 이름 : "<<name<<endl;
		cout<<"주     소 : "<<ad<<endl;
		cout<<"학     번 : "<<snum<<endl;
		cout<<"전화 번호 : "<<pnum<<endl;
	}

};

void Add(list<Student> &s);
void Search(list<Student> s);
void Delete(list<Student> &s);

int main(void)
{
	list<Student> s;
	int sel;
	while(1){
		cout<<"1. 학생정보 추가 2. 학생정보 검색 3. 학생정보 삭제 4.EXIT"<<endl;
		cout<<">>";
		cin>>sel;
		
		if(sel == 1){
			Add(s);
		}
		else if(sel == 2){
			Search(s);
		}
		else if(sel == 3){
			Delete(s);
		}
		else if(sel == 4){
			return 0;
		}
	}
	return 0;
}

void Add(list<Student> &s)
{
	string name, ad, pnum;
	int snum = 0;
	cout<<"학생 이름 : ";
	cin>>name;
	cout<<"주     소 : ";
	cin>>ad;
	cout<<"학     번 : ";
	cin>>snum;
	cout<<"전화 번호 : ";
	cin>>pnum;
	s.push_back(Student(name,ad,snum,pnum));
}
void Search(list<Student> s)
{
	list<Student>::iterator iter;
	string name;
	cout<<"찾을 이름 : ";
	cin>>name;
	for(iter = s.begin();iter != s.end(); iter++){
		if(iter->getName() == name){
			iter->print();
			return;
		}
	}
	cout<<"찾는 이름이 없습니다. "<<endl;
}
void Delete(list<Student> &s)
{
	list<Student>::iterator iter;
	string name;
	cout<<"삭제 할 이름 : ";
	cin>>name;
	for(iter = s.begin();iter != s.end();){
		if(iter->getName() == name){
			s.erase(iter);
			return;
		}
	}
	cout<<"삭제 할 이름이 없습니다. "<<endl;
}