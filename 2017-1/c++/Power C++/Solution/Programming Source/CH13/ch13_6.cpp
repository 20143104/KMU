#include <iostream>
#include <string>

using namespace std;

class Shape {
private:
	double startx;
	double starty;
	double area;
	double height;
	double width;
public:
	Shape(double x, double y, double h, double w)
	{
		startx = x;
		starty = y;
		height = h;
		width = w;
	}
	void setStartx(double x)
	{
		startx = x;
	}
	void setStarty(double y)
	{
		starty = y;
	}
	void setArea(double a)
	{
		area = a;
	}
	void setHeight(double h)
	{
		height = h;
	}
	void setWidth(double w)
	{
		width = w;
	}
	double getStartx()
	{
		return startx;
	}
	double getStarty()
	{
		return starty;
	}
	double getArea()
	{
		return area;
	}
	double getHeight()
	{
		return height;
	}
	double getWidth()
	{
		return width;
	}
	
};

class Rectangle : public Shape{
private:
	
public:
	Rectangle(double x, double y, double h, double w) : Shape(x,y,h,w)
	{

	}
	int getArea()
	{
		return getWidth()*getHeight();
	}
	
};

class Triangle : public Shape{
private:
	
public:
	Triangle(double x, double y, double h, double w) : Shape(x,y,h,w)
	{

	}
	int getArea()
	{
		return (getWidth()*getHeight())/2;
	}
	
};

int main()
{
	Rectangle r(3,4,5,2);
	Triangle t(4,5,2,5);

	cout<<"Rectangle 의 면적 : "<<r.getArea()<<endl;
	cout<<"Triangle 의 면적 : "<<t.getArea()<<endl;

		
	return 0;
}