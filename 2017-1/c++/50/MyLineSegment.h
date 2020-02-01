#ifndef _MY_LINE_SEGMENT_H_
#define _MY_LINE_SEGMENT_H_
#include "MyPoint.h"
class MyLineSegment
{
public:
    MyLineSegment ();
    MyLineSegment (const MyPoint& p, const MyPoint& q);
    MyLineSegment (const MyLineSegment& seg);
    bool isEndOfSegment(const MyPoint & p) const;
    bool isOnSegment(const MyPoint& p) const;
    bool properIntersection(const MyLineSegment &s)  const;
    bool improperIntersection(const MyLineSegment &s)  const;
    bool isLeftSide(const MyPoint &p) const;
    bool isRightSide(const MyPoint &p) const;
private:
    MyPoint p1, p2;
    int getArea2(const MyPoint &p) const;
};
#endif
