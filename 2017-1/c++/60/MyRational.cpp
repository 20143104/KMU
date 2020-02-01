#include "MyRational.h"
ostream &operator <<(ostream &outStream, const myRational& r)
{
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den;
    return outStream;
}
istream &operator >>(istream &inStream, myRational& r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}
long myRational::gcd(long m, long n)
{
  if (m == n)
    return n;
  else if (m < n)
    return gcd(m, n-m);
  else
    return gcd(m-n, n);
}
void myRational::reduce()
{
  if (_num == 0 || _den == 0)
  {
    _num = 0;
    _den = 1;
    return;
  }
  if (_den < 0)
  {
    _den *= -1;
    _num *= -1;
  }
  if (_num == 1)
    return;
  int sgn = (_num < 0 ? -1 : 1);
  long g = gcd(sgn * _num, _den);
  _num /= g;
  _den /= g;
}
myRational myRational::reciprocal(){
  return *this;
}
myRational::myRational(long num, long den):_num(num), _den(den){
  reduce();
}
myRational::myRational(const myRational &rat){
  _num = rat._num;
  _den = rat._den;
}
long myRational::getNumerator() const{
  return _num;
}
long myRational::getDenominator() const{
  return _den;
}
myRational myRational::operator+(const myRational &rat) const{
  int tmpnum = _num*rat._den + _den*rat._num;
  int tmpden = _den*rat._den;
  myRational tmp(tmpnum,tmpden);
  return tmp;
}
myRational myRational::operator-(const myRational &rat) const{
  int tmpnum = _num*rat._den - _den*rat._num;
  int tmpden = _den*rat._den;
  myRational tmp(tmpnum,tmpden);
  return tmp;
}
myRational myRational::operator*(const myRational &rat) const{
  int tmpnum = _num*rat._num;
  int tmpden = _den*rat._den;
  myRational tmp(tmpnum,tmpden);
  return tmp;
}
myRational myRational::operator/(const myRational &rat) const{
  if(_num==0 || rat._den==0){
    myRational tmp(0);
    return tmp;
  }
  int tmpnum = _num*rat._den;
  int tmpden = _den*rat._num;
  myRational tmp(tmpnum,tmpden);
  return tmp;
}
myRational myRational::operator+(long value) const{
  myRational tmp = *this;
  tmp._num = tmp._num+tmp._den*value;
  tmp.reduce();
  return tmp;
}
myRational myRational::operator-(long value) const{
  myRational tmp = *this;
  tmp._num = tmp._num-tmp._den*value;
  tmp.reduce();
  return tmp;
}
myRational myRational::operator*(long value) const{
  myRational tmp = *this;
  tmp._num = tmp._num*value;
  tmp.reduce();
  return tmp;
}
myRational myRational::operator/(long value) const{
  if(_num ==0 || value ==0){
    myRational tmp(0);
    return tmp;
  }
  myRational tmp = *this;
  tmp._den = tmp._den * value;
  tmp.reduce();
  return tmp;
}
myRational operator +(int value,const myRational &rat){
  int tmpnum = rat._den*value + rat._num;
  myRational tmp(tmpnum, rat._den);
  return tmp;
}
myRational operator-(int value, const myRational &rat){
  long tmpnum = rat._den*value - rat._num;
  myRational tmp(tmpnum, rat._den);
  tmp.reduce();
  return tmp;
}
myRational operator*(int value, const myRational &rat) {
  if (value == 0 || rat._num == 0){
    myRational tmp(0);
    return tmp;
  }
  long tmpnum = value*rat._num;
  myRational tmp(tmpnum, rat._den);
  tmp.reduce();
  return tmp;
}
myRational operator/(int value, const myRational &rat) {
  if(value == 0 || rat._num == 0) {
    myRational tmp = (0);
    return tmp;
  }
  long tmpnum = value*rat._den;
  myRational tmp(tmpnum, rat._num);
  tmp.reduce();
  return tmp;
}
myRational& myRational::operator++(){
  _num = _num+_den;
  reduce();
  return *this;
}
myRational& myRational::operator--(){
  _num = _num-_den;
  reduce();
  return *this;
}
myRational myRational::operator++(int){
  myRational tmp = *this;
  *this = *this + 1;
  reduce();
  return tmp;
}
myRational myRational::operator--(int){
  myRational tmp = *this;
  _num = _num-_den;
  reduce();
  return tmp;
}
myRational myRational::operator-(){
  return myRational(-1*_num,_den);
}
myRational myRational::operator=(const myRational &rat){
  _num = rat._num;
  _den = rat._den;
  return *this;
}
myRational myRational::operator+=(const myRational &rat){
  _num = _num*rat._den + rat._num*_den;
  _den = _den * rat._den;
  reduce();
  return *this;
}
myRational myRational::operator-=(const myRational &rat){
  _num = _num*rat._den - rat._num*_den;
  _den = _den * rat._den;
  reduce();
  return *this;
}
myRational myRational::operator*=(const myRational &rat){
  _num = _num*rat._num;
  _den = _den * rat._den;
  reduce();
  return *this;
}
myRational myRational::operator/=(const myRational &rat){
  if(_num==0 || rat._den==0){
    _num = 0;
    _den = 1;
    return *this;
  }
  _num = _num*rat._den;
  _den = _den * rat._num;
  reduce();
  return *this;
}
myRational myRational::operator=(long value){
  _num = value;
  _den = 1;
  return *this;
}
myRational myRational::operator+=(long value){
  _num = _num+value*_den;
  reduce();
  return *this;
}
myRational myRational::operator-=(long value){
  _num = _num-value*_den;
  reduce();
  return *this;
}
myRational myRational::operator*=(long value){
  _num = _num*value;
  reduce();
  return *this;
}
myRational myRational::operator/=(long value){
  if(value==0 || _num==0){
    _num = 0;
    _den = 1;
    return *this;
  }
  _den = _den*value;
  reduce();
  return *this;
}
bool myRational::operator<(const myRational &rat) const{
  if(_num * rat._den < rat._num * _den)
    return true;
  else
    return false;
}
bool myRational::operator<=(const myRational &rat) const{
  if(_num * rat._den <= rat._num * _den)
    return true;
  else
    return false;
}
bool myRational::operator>(const myRational &rat) const{
  if(_num * rat._den > rat._num * _den)
    return true;
  else
    return false;
}
bool myRational::operator>=(const myRational &rat) const{
  if(_num * rat._den >= rat._num * _den)
    return true;
  else
    return false;
}
bool myRational::operator==(const myRational &rat) const{
  if(_num * rat._den == rat._num * _den)
    return true;
  else
    return false;
}
bool myRational::operator!=(const myRational &rat) const{
  if(_num * rat._den != rat._num * _den)
    return true;
  else
    return false;
}
bool myRational::operator<(long value) const{
  if(_num < value * _den)
    return true;
  else
    return false;
}
bool myRational::operator<=(long value) const{
  if(_num <= value * _den)
    return true;
  else
    return false;
}
bool myRational::operator>(long value) const{
  if(_num > value * _den)
    return true;
  else
    return false;
}
bool myRational::operator>=(long value) const{
  if(_num >= value * _den)
    return true;
  else
    return false;
}
bool myRational::operator==(long value) const{
  if(_num == value * _den)
    return true;
  else
    return false;
}
bool myRational::operator!=(long value) const{
  if(_num != value * _den)
    return true;
  else
    return false;
}
