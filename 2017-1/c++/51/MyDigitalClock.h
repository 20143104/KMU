#ifndef _MY_DIGITAL_CLOCK_H_
#define _MY_DIGITAL_CLOCK_H_
#include <iostream>
using namespace std;
class MyDigitalClock
{
public:
    friend ostream& operator<< (ostream&, const MyDigitalClock&
);
    // constructors
    MyDigitalClock (int h=12, int m=0, bool ap=false);
    MyDigitalClock (char clock[]);
    MyDigitalClock tick();
    MyDigitalClock untick();
    MyDigitalClock operator++();    // prefix, ++c
    MyDigitalClock operator++(int); // postfix, c++
    MyDigitalClock operator--();    // prefix, --c
    MyDigitalClock operator--(int); // postfix, c--
private:
    int hour;
    int min;
    bool am_pm;
};
#endif // _MY_DIGITAL_CLOCK_H
