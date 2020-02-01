#include <iostream>
#include <string>
#define PI 3.141592

using namespace std;

class Shape
{
protected:
	string name;
public:
	Shape(string n)
	{
		name = n;
	}
	virtual double getSurfaceArea() = 0;
	virtual void print(){}
};

class Shpere : public Shape
{
private:
	int radius;
public:
	Shpere(string n, int r) : Shape(n)
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
	double getSurfaceArea()
	{
		return 4*radius*radius*PI;
	}
	void print()
	{
		cout<<name<<endl;
		cout<<"參創檜 : "<<getSurfaceArea()<<endl;
	}
};

class Cube : public Shape
{
private:
	int width;
	int height;
	int base;
public:
	Cube(int w, int h, int b, string n) : Shape(n)
	{
		width = w;
		height = h;
		base = b;
	}
	double getSurfaceArea()
	{
		return (width*height+height*base+base*width)*2;
	}
	void print()
	{
		cout<<name<<endl;
		cout<<"參創檜 : "<<getSurfaceArea()<<endl;
	}
};

class Cylinder : public Shape
{
private:
	int radius;
	int height;
public:
	Cylinder(int h, int r, string n) : Shape(n)
	{
		radius = r;
		height = h;
	}
	double getSurfaceArea()
	{
		return radius*radius*PI*height;
	}
	void print()
	{
		cout<<name<<endl;
		cout<<"參創檜 : "<<getSurfaceArea()<<endl;
	}

};

int main(void)
{
	Shape *arrayOfShapes[3];
	arrayOfShapes[0] = new Shpere("Shpere",3);
	arrayOfShapes[1] = new Cube(4,5,6,"Cube");
	arrayOfShapes[2] = new Cylinder(7,3,"Cylinder");

	for(int i = 0; i < 3 ; i++){
		arrayOfShapes[i]->print();
	}
	return 0;
}