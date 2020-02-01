#ifndef _MY_POINT_H_
#define _MY_POINT_H_
class MyPoint
{
public:
    MyPoint();
    MyPoint(int coordX, int coordY);
    MyPoint(const MyPoint& p);
    int getX() const;
    int getY() const;
private:
    int x, y;
};
#endif // _MY_POINT_H_
