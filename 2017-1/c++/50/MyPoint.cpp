#include <cstdlib>
#include "MyPoint.h"

MyPoint::MyPoint():x(0), y(0){}
MyPoint::MyPoint(int coordX, int coordY):x(coordX),y(coordY){}
MyPoint::MyPoint(const MyPoint& p){
    x = p.x;
    y = p.y;
}
int MyPoint::getX() const{
    return x;
}
int MyPoint::getY() const{
    return y;
}
