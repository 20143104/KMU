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
		cout<<"영화제목 : "<<name<<endl;
		cout<<"감    독 : "<<director<<endl;
		cout<<"평    점 : "<<point<<endl;
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
	Movie m1("아저씨","이정범",9.28), m2("슈퍼배드","피에르 꼬팽",8.96), m3;

	m3.setName("무적자");
	m3.setDirector("송해성");
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
			cout<<"가장 평점이 좋은 영화 : "<<m1.getName()<<endl;
		else
			cout<<"가장 평점이 좋은 영화 : "<<m3.getName()<<endl;
	}
	else{
		if(p2 > p3)
			cout<<"가장 평점이 좋은 영화 : "<<m2.getName()<<endl;
		else
			cout<<"가장 평점이 좋은 영화 : "<<m3.getName()<<endl;
	}

	cout<<endl;
	return 0;	
}
