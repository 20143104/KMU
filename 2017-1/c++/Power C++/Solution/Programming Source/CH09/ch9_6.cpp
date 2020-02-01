#include <iostream.h>
#include <string>

class Complex{
private : 
	double real;
	double imagine;  

public :
	double getReal();
	double getImagine();
	void setComplex(double real, double imagine);
	void Add(double real1, double real2, double imagine1, double imagine2);
	void Sub(double real1, double real2, double imagine1, double imagine2);
	void Print();
};

double Complex::getReal()
{
	return real;
}
double Complex::getImagine()
{
	return imagine;
}
void Complex::setComplex(double real, double imagine)
{
	this->real = real;
	this->imagine = imagine;
}

void Complex::Add(double real1, double real2, double imagine1, double imagine2)
{
	real = real1 + real2;
	imagine = imagine1 + imagine2;
}

void Complex::Sub(double real1, double real2, double imagine1, double imagine2)
{
	real = real1 - real2;
	imagine = imagine1 - imagine2;
}

void Complex::Print()
{
	cout<<real<<" + "<< imagine<<"i"<<endl;
}

int main()
{
	double r1, i1, r2, i2;
	Complex c1, c2, c3;

	cout<<"1번째 실수부와 허수부를 입력하세요 :";
	cin>>r1>>i1;

	cout<<"2번째 실수부와 허수부를 입력하세요 :";
	cin>>r2>>i2;
	
	cout<<"==================================="<<endl;
	c1.setComplex(r1,i1);
	cout<<"복소수는 : ";
	c1.Print();
	c2.setComplex(r2,i2);
	cout<<"복소수는 : ";
	c2.Print();
	c3.Add(r1,r2,i1,i2);
	cout<<"합은 : ";
	c3.Print();
	c3.Sub(r1,r2,i1,i2);
	cout<<"뺄셈은 : ";
	c3.Print();
	cout<<"==================================="<<endl;
	
	return 0;
}