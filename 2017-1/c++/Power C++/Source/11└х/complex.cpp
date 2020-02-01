#include <iostream>
using namespace std;

class Complex
{
private:
	double real;		// �Ǽ���
	double imag;	// �����

public:
	Complex();		// ������
	Complex(double a, double b); // ������
	~Complex();		// �Ҹ���

	double getReal();	// �Ǽ��θ� ��ȯ�Ѵ�.
	double getImag();	//����θ� ��ȯ�Ѵ�.
	Complex add(const Complex& c);	// ���Ҽ��� ���� ������ �����Ѵ�. 
	void print();		// ���Ҽ��� ����Ѵ�. 
};

Complex::Complex()
{
	real = 0;
	imag = 0;
}

Complex::Complex(double a, double b)
{
	real = a;
	imag = b;
}

Complex::~Complex()
{
}

double Complex::getReal()
{
	return(real);
}

double Complex::getImag()
{
	return(imag);
}
// ���Ҽ��� ���� ���� ����
Complex Complex::add(const Complex& c)
{
	Complex temp;	// �ӽ� ��ü
	temp.real = this->real + c.real;
	temp.imag = this->imag + c.imag;

	return(temp);	// ��ü�� ��ȯ�Ѵ�.
}

void Complex::print()
{
	cout << real << " + " << imag << "i" << endl;
}

int main(void)
{
	Complex x(2, 3), y(4, 6), z;

	cout << "ù��° ���Ҽ� x: ";
	x.print();

	cout << "�ι�° ���Ҽ� y: ";
	y.print();

	z = x.add(y);		// z = x + y

	cout << " z = x + y = ";
	z.print();

	return(0);
}
