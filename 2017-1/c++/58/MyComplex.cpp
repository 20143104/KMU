//MyComplex.cpp
#include "MyComplex.h"
// Constructor
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Copy constructor
myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}

// Accessor functions
int myComplex::getRealPart() const
{
    return realPart;
}
int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}

// Mutator functions
void myComplex::setRealPart(int real)
{
    realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}

// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
    myComplex tmp;
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    tmp.realPart = newReal;
    tmp.imaginaryPart = newImag;
    return tmp;
}
myComplex myComplex::operator +(int value) const
{
    return myComplex(value) + (*this);
}
myComplex myComplex::operator -(const myComplex& number) const
{
    myComplex tmp = *this;
    tmp.realPart -= number.realPart;
    tmp.imaginaryPart -= number.imaginaryPart;
    return tmp;
}
myComplex myComplex::operator -(int value) const
{
    return (*this) - myComplex(value);
}
myComplex myComplex::operator *(const myComplex& number) const
{
    int newreal = this->realPart*number.realPart - this->imaginaryPart*number.imaginaryPart;
    int newimag = this->realPart*number.imaginaryPart + this->imaginaryPart*number.realPart;
    return myComplex(newreal, newimag);
}
myComplex myComplex::operator *(int value) const
{
    return myComplex(value*realPart, value*imaginaryPart);
}

// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(int value)
{
    this->realPart = value;
    this->imaginaryPart = 0;
    return *this;
}
myComplex& myComplex::operator +=(const myComplex& number)
{
    this->realPart += number.realPart;
    this->imaginaryPart += number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator +=(int value)
{
    this->realPart += value;
    return *this;
}
myComplex& myComplex::operator -=(const myComplex& number)
{
    this->realPart -= number.realPart;
    this->imaginaryPart -= number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator -=(int value)
{
    this->realPart -= value;
    return *this;
}
myComplex& myComplex::operator *=(const myComplex& number)
{
    int newreal = this->realPart*number.realPart -this->imaginaryPart*number.imaginaryPart;
    int newimg = this->realPart*number.imaginaryPart +this->imaginaryPart*number.realPart;
    this->realPart = newreal;
    this->imaginaryPart = newimg;
    return *this;
}
myComplex& myComplex::operator *=(int value)
{
    this->realPart *= value;
    this->imaginaryPart *= value;
    return *this;
}

// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
    return (realPart == number.realPart) &&
        (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const
{
    return !(*this == number);
}
bool myComplex::operator >(const myComplex& number) const
{
    return norm() > number.norm();
}
bool myComplex::operator >=(const myComplex& number) const
{
    return norm() >= number.norm();
}
bool myComplex::operator <(const myComplex& number) const
{
    return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const
{
    return norm() <= number.norm();
}

// Overloaded unary operators
myComplex myComplex::operator -() // unary minus
{
    return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex:: operator ~()
{
    return myComplex(realPart, -imaginaryPart);
}
myComplex& myComplex:: operator ++()//prefix
{
    realPart++;
    return *this;
}
myComplex& myComplex:: operator --()//prefix
{
    realPart--;
    return *this;
}
myComplex myComplex:: operator ++(int)//postfix
{
    myComplex tmp = *this;
    this->realPart++;
    return tmp;
}
myComplex myComplex:: operator --(int)//postfix
{
    myComplex tmp = *this;
    this->realPart--;
    return tmp;
}

// private function
int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}
//friend
ostream &operator <<(ostream &outStream, const myComplex& number)
{
    outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return outStream;
}
istream &operator >>(istream &inStream, myComplex& number)
{
    inStream >> number.realPart >> number.imaginaryPart;
    return inStream;
}
myComplex operator +(int value, const myComplex& number)
{
    myComplex com = number;
    com.realPart += value;
    return com;
}
myComplex operator -(int value, const myComplex& number)
{
    myComplex tmp = number;
    tmp.realPart = -1*tmp.realPart;
    tmp.imaginaryPart = -1*tmp.imaginaryPart;
    tmp.realPart += value;
    return tmp;
}
myComplex operator *(int value, const myComplex& number)
{
    myComplex tmp = number;
    tmp.realPart *= value;
    tmp.imaginaryPart *= value;
    return tmp;
}
