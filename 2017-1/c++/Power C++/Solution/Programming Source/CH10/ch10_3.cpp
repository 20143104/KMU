#include <iostream>
#include <string>

using namespace std;

class Movie
{
private:
	string name;
	string director;
	double point;
public:
	Movie(){}
	Movie(string name, string director,double point)
	{
		this->name = name;
		this->director = director;
		this->point = point;
	}
	void print()
	{
		cout<<"��ȭ���� : "<<name<<endl;
		cout<<"��    �� : "<<director<<endl;
		cout<<"��    �� : "<<point<<endl;
	}
	string getName()
	{
		return name;
	}
	string getDirector()
	{
		return director;
	}
	double getPoint()
	{
		return point;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setDirector(string director)
	{
		this->director = director;
	}
	void setPoint(double point)
	{
		this->point = point;
	}	
};

int main()
{
	double p1,p2,p3;
	Movie m1("������","������",9.28), m2("���۹��","�ǿ��� ����",8.96), m3;

	m3.setName("������");
	m3.setDirector("���ؼ�");
	m3.setPoint(6.08);

	cout<<"========================================"<<endl;
	m1.print();
	m2.print();
	m3.print();
	cout<<"========================================"<<endl;
	p1 = m1.getPoint();
	p2 = m2.getPoint();
	p3 = m3.getPoint();

	if(p1 > p2){
		if(p1 > p3)
			cout<<"���� ������ ���� ��ȭ : "<<m1.getName()<<endl;
		else
			cout<<"���� ������ ���� ��ȭ : "<<m3.getName()<<endl;
	}
	else{
		if(p2 > p3)
			cout<<"���� ������ ���� ��ȭ : "<<m2.getName()<<endl;
		else
			cout<<"���� ������ ���� ��ȭ : "<<m3.getName()<<endl;
	}

	cout<<endl;
	return 0;	
}
