#include "MyLineSegment.h"

MyLineSegment::MyLineSegment():p1(0,0),p2(0,0){}
MyLineSegment::MyLineSegment(const MyPoint& p, const MyPoint& q): p1(p),p2(q){}
MyLineSegment::MyLineSegment(const MyLineSegment& s):p1(s.p1),p2(s.p2){

}
///점 p가 p3 p4 위에 있는지를 검사
bool MyLineSegment::isEndOfSegment(const MyPoint & p) const{
  if((p.getX()==p1.getX() && p.getY()==p1.getY()) || (p.getX()==p2.getX() && p.getY()==p2.getY()))
    return true;
  else
    return false;
}
//점 p가 p3,p4사이에 있는 지를 검사
bool MyLineSegment::isOnSegment(const MyPoint& p) const {
  if(isEndOfSegment(p))
    return false;
  if ((p2.getX() - p1.getX())*(p.getY() - p1.getY()) - (p.getX() - p1.getX())*(p2.getY() -p1.getY())==0)
    return true;
  else
    return false;
}
bool MyLineSegment::properIntersection(const MyLineSegment &s) const{
  if((isLeftSide(s.p1) && isRightSide(s.p2)) || (isLeftSide(s.p2) && isRightSide(s.p1))){
    if((s.isLeftSide(p1) && s.isRightSide(p2))|| (s.isLeftSide(p2)&&s.isRightSide(p1))){
      return true;
    }
    else{
      return false;
    }
  }
  else
    return false;
}
bool MyLineSegment::improperIntersection(const MyLineSegment &s)const{
  if(isEndOfSegment(s.p1)||isEndOfSegment(s.p2)||isOnSegment(s.p1)||isOnSegment(s.p2)||s.isEndOfSegment(p1)||s.isEndOfSegment(p2)||s.isOnSegment(p1)||s.isOnSegment(p2))
    return true;
  else
    return false;

}
int MyLineSegment::getArea2(const MyPoint &p) const 
{
    int p1x, p2x, px, p1y, p2y, py;
    p1x = p1.getX();
    p1y = p1.getY();
    p2x = p2.getX();
    p2y = p2.getY();
    px  = p.getX();
    py  = p.getY();
    return p1x * p2y - p1y * p2x +
           p1y * px  - p1x * py +
           p2x * py  - px * p2y;
}
bool MyLineSegment::isLeftSide(const MyPoint &p) const {
  return getArea2(p)>0;
}

bool MyLineSegment::isRightSide(const MyPoint &p) const{
  return getArea2(p)<0;
}
