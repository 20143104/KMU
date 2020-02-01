#include <iostream>
using namespace std;

class Complex
{
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

	Complex operator+(const Complex y) const
	{
		Complex result;
		result.real = this->real + y.real;
		result.imag = this->imag + y.imag;
		return result;
	}

	Complex operator-(const Complex y) const
	{
		Complex result;
		result.real = this->real - y.real;
		result.imag = this->imag - y.imag;
		return result;
	}
	
	Complex operator*(const Complex y) const
	{
		Complex result;
		result.real = this->real * y.real;
		result.imag = this->imag * y.imag;
		return result;
	}

	Complex add(const Complex& c)
	{
		Complex temp;
		temp.real = this->real + c.real;
		temp.imag = this->imag + c.imag;
		
		return(temp);
	}

	ostream& operator<<(ostream& os)
	{
		os<< real << " + " << imag << "i" << endl;
		return os;
	}
	istream& operator>>(istream& is)
	{
		is >> real >> imag;
		return is;
	}

	void print() {	cout << real << " + " << imag << "i" << endl; }
};


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
	
	cout << "z<<cout -> ";
	z<<cout; 
	
	cout << "z>>cin -> ";
	z>>cin;

	z<<cout;
	
	return(0);
}
