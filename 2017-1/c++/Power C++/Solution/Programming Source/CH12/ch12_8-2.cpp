#include <iostream>

using std::ostream;
using std::istream;
using std::endl;
using std::cout;
using std::cin;

class Complex
{
	friend Complex operator+(const Complex& x, const Complex& y);
	friend Complex operator-(const Complex& x, const Complex& y);
	friend Complex operator*(const Complex& x, const Complex& y);
	friend ostream& operator<<(ostream& os, const Complex& c);
	friend istream& operator>>(istream& i, const Complex& c);

private:
	double real;	
	double imag;		
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(double a, double b)
	{
		real = a;
		imag = b;
	}

	~Complex(){}
	
	double getReal() {	return(real); }
	double getImag() {	return(imag); }


	void print() {	cout << real << " + " << imag << "i" << endl; }
};

Complex operator+(const Complex& x, const Complex& y)
{
	Complex result;
	result.real = x.real + y.real;
	result.imag = x.imag + y.imag;
	return result;
}

Complex operator-(const Complex& x, const Complex& y)
{
	Complex result;
	result.real = x.real - y.real;
	result.imag = x.imag - y.imag;
	return result;
}

Complex operator*(const Complex& x, const Complex& y)
{
	Complex result;
	result.real = x.real * y.real;
	result.imag = x.imag * y.imag;
	return result;
}
	
ostream& operator<<(ostream& os, const Complex& c)
{
	os<< c.real << " + " << c.imag << "i" << endl;
	return os;
}
istream& operator>>(istream& is, const Complex& c)
{
	is>>(double)c.real>>(double)c.imag;
	return is;
}

int main(void)
{
	Complex x(2, 3), y(4, 6), z;
	
	cout << "첫번째 복소수 x: ";
	x.print();
	
	cout << "두번째 복소수 y: ";
	y.print();
	
	z = x + y;	
	cout << "x + y = ";
	z.print();
	
	z = x - y;	
	cout << "x - y = ";
	z.print();

	z = x * y;	
	cout << "x * y = ";
	z.print();
	
	cout << "cout<<z -> ";
	cout<<z; 
	
	cout << "cin<<z -> ";
	cin>>z;

	cout<<z;
	
	return(0);
}
