#include <iostream>

using namespace std;

class Point{
private:
	int x,y;
public:
	Point() : x(0),y(0){ }
	Point(int xloc, int yloc)
	{
		x = xloc;
		y = yloc;
	}
	Point(Point& p) 
	{
		x = p.x;
		y = p.y;
	}
	~Point(void) { }
	
	Point operator+(Point y) 
	{
		Point result;
		result.x = this->x + y.x;
		result.y = this->y + y.y;
		return result;
	}
	
	Point operator-(Point y)
	{
		Point result;
		result.x = this->x - y.x;
		result.y = this->y - y.y;
		return result;
	}	
	void display()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
};

int main()
{
	Point p1(100, 200);
	Point p2(200, 300);
	Point p3;

	cout<<"p1 = ";
	p1.display();
	cout<<"p2 = ";
	p2.display();
	
	p3 = p1 + p2;
	cout<<"p1 + p2 = ";
	p3.display();
	p3 = p1 - p2;
	cout<<"p1 - p2 = ";
	p3.display();
	
	return 0;
}

