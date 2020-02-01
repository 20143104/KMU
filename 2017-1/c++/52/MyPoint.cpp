#include <cstdlib>
#include "MyPoint.h"
// constructors
MyPoint::MyPoint ()
:x(0), y(0)         // set default to origin (0,0)
{
}
MyPoint::MyPoint (int coordX, int coordY)
:x(coordX), y(coordY)
{
}
MyPoint::MyPoint (const MyPoint& p)
{
  x=p.getX();
  y=p.getY();
}
// accessor functions
int MyPoint::getX () const
{
    return x;
}
int MyPoint::getY () const
{
    return y;
}
// mutator functions
void MyPoint::setX (int coordX)
{
    x = coordX;
}
void MyPoint::setY (int coordY)
{
    y = coordY;
}
bool MyPoint::operator== (const MyPoint& p) const
{
  if(x==p.getX() && y==p.getY())
    return true;
  else
    return false;
}
bool MyPoint::operator!= (const MyPoint& p) const
{
    return !operator==(p);
}
//직선거리(Euclidean distance)의제곱을계산
int MyPoint::dist2sqr(const MyPoint& p) const
{
  return (x-p.getX())*(x-p.getX())+(y-p.getY())*(y-p.getY());
}
//직각거리(rectilinear distance)를계산
int MyPoint::dist1(const MyPoint& p) const
{
  int sum=0;
  if(x>p.getX())
    sum+=(x-p.getX());
  else
    sum+=(p.getX()-x);

  if(y>p.getY())
    sum+=(y-p.getY());
  else
    sum+=(p.getY()-y);

  return sum;

}
