#include <iostream>
#include <string>
#define PI 3.141592

using namespace std;

class Shape
{
protected:
	int x,y;
public:
	void setOrigin(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	virtual void draw()
	{
		cout<<"Shape Draw"<<endl;
	}
	virtual void move(int x, int y)
	{

	}
	virtual double getArea() = 0;
	virtual Shape* createShape() = 0;
};

class Rectangle : public Shape
{
private:
	int width, height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void draw()
	{
		cout<<"Rectangle Draw"<<endl;
		cout<<"시작점 : ( "<<x<<" , "<<y<<" )"<<endl;
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout<<"이동점 : ( "<<x<<" , "<<y<<" )"<<endl;
		cout<<"시작점 : ( "<<this->x<<" , "<<this->y<<" )"<<endl;
	}
	double getArea() 
	{
		return width*height;
	}
	virtual Shape* createShape()
	{
		Shape *s = NULL;
		s = new Rectangle();
		return s;
	}
};
class Ellipse : public Shape
{
private:
	int width, height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void draw()
	{
		cout<<"Ellipse Draw"<<endl;
		cout<<"시작점 : ( "<<x<<" , "<<y<<" )"<<endl;
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout<<"이동점 : ( "<<x<<" , "<<y<<" )"<<endl;
		cout<<"시작점 : ( "<<this->x<<" , "<<this->y<<" )"<<endl;
	}
	double getArea() 
	{
		return width*height*PI/4;
	}
	virtual Shape* createShape()
	{
		Shape *s = NULL;
		s = new Ellipse();
		return s;
	}
};
class Triangle : public Shape
{
private:
	int width, height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void draw()
	{
		cout<<"Triangle Draw"<<endl;
		cout<<"시작점 : ( "<<x<<" , "<<y<<" )"<<endl;
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout<<"이동점 : ( "<<x<<" , "<<y<<" )"<<endl;
		cout<<"시작점 : ( "<<this->x<<" , "<<this->y<<" )"<<endl;
	}
	double getArea() 
	{
		return width*height/2;
	}
	virtual Shape* createShape()
	{
		Shape *s = NULL;
		s = new Triangle();
		return s;
	}
};
int main()
{
	Rectangle r;
	Ellipse e;
	Triangle t;
	Shape *pr = r.createShape();
	Shape *pe = e.createShape();
	Shape *pt = t.createShape();	
	pr->setOrigin(3,5);
	((Rectangle *)pr)->setWidth(4);
	((Rectangle *)pr)->setHeight(2);
	pe->setOrigin(3,3);
	((Ellipse *)pe)->setWidth(4);
	((Ellipse *)pe)->setHeight(2);
	pt->setOrigin(2,2);
	((Triangle *)pt)->setWidth(4);
	((Triangle *)pt)->setHeight(2);
	pr->draw();
	cout<<"면  적 : "<<pr->getArea()<<endl;
	pr->move(2,1);
	pe->draw();
	cout<<"면  적 : "<<pe->getArea()<<endl;
	pe->move(2,0);
	pt->draw();
	cout<<"면  적 : "<<pt->getArea()<<endl;
	pt->move(0,1);
	return 0;
}
