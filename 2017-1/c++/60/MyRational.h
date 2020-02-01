#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_
#include <iostream>
using namespace std;
class myRational
{
public:
  friend ostream &operator <<(ostream &outStream, const myRational& r);
  friend istream &operator >>(istream &inStream,myRational& r);
  friend myRational operator +(int value, const myRational &rat);
  friend myRational operator-(int value, const myRational &rat);
  friend myRational operator*(int value, const myRational &rat);
  friend myRational operator/(int value, const myRational &rat);
  myRational(long num = 0, long den = 1);
  myRational(const myRational &rat);
  //////constructor
  long getNumerator() const;
  long getDenominator() const;
  ////////accessor
  myRational operator+(const myRational &rat) const;
  myRational operator-(const myRational &rat) const;
  myRational operator*(const myRational &rat) const;
  myRational operator/(const myRational &rat) const;
  myRational operator+(long value) const;
  myRational operator-(long value) const;
  myRational operator*(long value) const;
  myRational operator/(long value) const;
  ////////////////overloaded
  myRational& operator++();  //전위
  myRational& operator--();
  myRational operator++(int);
  myRational operator--(int);
  myRational operator-();
  ////////////////////////////////////
  myRational operator=(const myRational &rat);
  myRational operator+=(const myRational &rat);
  myRational operator-=(const myRational &rat);
  myRational operator*=(const myRational &rat);
  myRational operator/=(const myRational &rat);
  myRational operator=(long value);
  myRational operator+=(long value);
  myRational operator-=(long value);
  myRational operator*=(long value);
  myRational operator/=(long value);
  /////////////assingn////////////////
  bool operator<(const myRational &rat) const;
  bool operator<=(const myRational &rat) const;
  bool operator>(const myRational &rat) const;
  bool operator>=(const myRational &rat) const;
  bool operator==(const myRational &rat) const;
  bool operator!=(const myRational &rat) const;
  bool operator<(long value) const;
  bool operator<=(long value) const;
  bool operator>(long value) const;
  bool operator>=(long value) const;
  bool operator==(long value) const;
  bool operator!=(long value) const;
  //////////////////comparison
private:
    // 분수는항상내부적으로기약분수로표현하며, 또한항상_den>0 이다.
    long _num;          // numerator
    long _den;          // denominator
    long gcd(long m, long n);   // 최대공약수
    void reduce();
    myRational reciprocal();

};
#endif
