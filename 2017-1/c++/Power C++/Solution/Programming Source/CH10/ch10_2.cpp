#include <iostream>

using namespace std;

class Box
{
private:
	double width;
	double length;
	double height;
	bool inEmpty;
public:
	Box()
	{
		width = 5;
		length = 6; 
		height = 7;
		inEmpty = true;	
	}
	Box(double w, double l,double h,bool i)
	{
		width = w;
		length = l;
		height = h;
		inEmpty = i;
	}
	void print()
	{
		cout<<"���Ǵ� : "<<width*length*height<<endl;
	}
	double getWidth()
	{
		return width;
	}
	double getLength()
	{
		return length;
	}
	double getHeight()
	{
		return height;
	}
	void setWidth(double w)
	{
		width = w;
	}
	void setLength(double l)
	{
		length = l;
	}
	void setHeight(double h)
	{
		height = h;
	}	
	bool empty()
	{
		return inEmpty;
	}
	double getVolume()
	{	
		return (width*length*height);
	}	
};

int main()
{
	double vb1,vb2,vb3;
	Box b1(3.5,4.4,5.0, false), b2, b3;

	b3.setHeight(4.0);
	b3.setLength(5.0);
	b3.setWidth(2.4);

	cout<<"========================================"<<endl;
	cout<<"�ڽ� 1 "; b1.print();
	cout<<"�ڽ� 2 "; b2.print();
	cout<<"�ڽ� 3 "; b3.print();
	cout<<"========================================"<<endl;
	vb1 = b1.getVolume();
	vb2 = b2.getVolume();
	vb3 = b3.getVolume();

	if(vb1 > vb2){
		if(vb1 > vb3)
			cout<<"�ڽ�1�� ���ǰ� ���� Ů�ϴ� : "<<vb1;
		else
			cout<<"�ڽ�3�� ���ǰ� ���� Ů�ϴ� : "<<vb3;
	}
	else{
		if(vb2 > vb3)
			cout<<"�ڽ�2�� ���ǰ� ���� Ů�ϴ� : "<<vb2;
		else
			cout<<"�ڽ�3�� ���ǰ� ���� Ů�ϴ� : "<<vb3;
	}

	cout<<endl;
	return 0;	
}