#include <iostream>
#include <string>

using namespace std;

class Triangle
{
private:
	double base;
	double height;
	double area;
public:
	void setBase(double base)
	{
		this->base = base;
	}
	double getBase()
	{
		return base;
	}
	void setHeight(double height)
	{
		this->height = height;
	}
	double getHeight()
	{
		return height;
	}
	double getArea()
	{
		area = base*height/2;
		return area;
	}
};

int main()
{
	Triangle t1;
	double base = 0, height = 0;

	cout<<"�ﰢ���� �غ� : ";
	cin>>base;
	t1.setBase(base);
	cout<<"�ﰢ���� ���� : ";
	cin>>height;
	t1.setHeight(height);
	cout<<"�ﰢ���� ���̴� "<<t1.getArea()<<"�Դϴ�."<<endl;
	return 0;
}
