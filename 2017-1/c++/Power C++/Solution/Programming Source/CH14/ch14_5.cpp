#include <iostream>
#include <string>
#define PI 3.141592

using namespace std;

class Shape
{
protected:
	int width;
	int height;
public:
	Shape(int w, int h)
	{
		width = w;
		height = h;
	}
	virtual void print(){}
};

class TwoDimShape : public Shape
{
private:
	int area;
public:
	TwoDimShape(int w, int h) : Shape(w, h){}
	virtual double getArea()
	{
		return area;
	}
	void print(){}

};

class ThreeDimShape : public Shape
{
private:
	int volume;
public:
	ThreeDimShape(int w, int h) : Shape(w,h){}
	virtual double getVolume()
	{
		return volume;
	}
	void print(){}
};

class Rectangle : public TwoDimShape
{
public:
	Rectangle(int w, int h) : TwoDimShape(w, h){}
	void print()
	{
		cout<<"Rectangle"<<endl;
		cout<<"搁利 : "<<getArea()<<endl;
	}
	double getArea() 
	{
		return width*height;
	}
};

class Ellipse : public TwoDimShape
{
public:
	Ellipse(int w, int h) : TwoDimShape(w, h){}
	void print()
	{
		cout<<"Ellipse"<<endl;
		cout<<"搁利 : "<<getArea()<<endl;
	}
	double getArea() 
	{
		return width*height*PI/4;
	}
};

class Triangle : public TwoDimShape
{
public:
	Triangle(int w, int h) : TwoDimShape(w, h){}
	void print()
	{
		cout<<"Triangle"<<endl;
		cout<<"搁利 : "<<getArea()<<endl;
	}
	double getArea() 
	{
		return width*height/2;
	}
};

class Shpere : public ThreeDimShape
{
private:
	int radius;
public:
	Shpere(int w, int h, int r) : ThreeDimShape(w, h)
	{
		radius = r;
	}
	void setRadius(int r)
	{
		radius = r;
	}
	int getRadius()
	{
		return radius;
	}
	double getVolume()
	{
		return ((double)3/4)*radius*radius*radius*PI;
	}
	void print()
	{
		cout<<"Cylinder"<<endl;
		cout<<"眉利 : "<<getVolume()<<endl;
	}
};

class Cube : public ThreeDimShape
{
private:
	int base;
public:
	Cube(int w, int h, int b) : ThreeDimShape(w, h)
	{
		base = b;
	}
	void setBase(int b)
	{
		base = b;
	}
	int getBase()
	{
		return base;
	}
	double getVolume()
	{
		return width*height*base;
	}
	void print()
	{
		cout<<"Cube"<<endl;
		cout<<"眉利 : "<<getVolume()<<endl;
	}
};

class Cylinder : public ThreeDimShape
{
private:
	int radius;
public:
	Cylinder(int w, int h, int r) : ThreeDimShape(w, h)
	{
		radius = r;
	}
	void setRadius(int r)
	{
		radius = r;
	}
	int getRadius()
	{
		return radius;
	}
	double getVolume()
	{
		return radius*radius*PI*height;
	}
	void print()
	{
		cout<<"Cylinder"<<endl;
		cout<<"眉利 : "<<getVolume()<<endl;
	}

};

int main(void)
{
	TwoDimShape *t1,*t2,*t3;
	ThreeDimShape *t4,*t5,*t6;
	
	t1 = new Ellipse(1,2);
	t2 = new Rectangle(3,4);
	t3 = new Triangle(5,6);
	t4 = new Shpere(7,8,9);
	t5 = new Cube(10,11,12);
	t6 = new Cylinder(13,14,15);

	t1->print();
	t2->print();
	t3->print();
	t4->print();
	t5->print();
	t6->print();

	return 0;
}