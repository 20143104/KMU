#include <iostream>
using namespace std;

class myDate {
  friend ostream &operator <<(ostream &outstream, const myDate &date);
  friend istream &operator >>(istream &instream,myDate &date);
  friend myDate operator +(int num, const myDate &date);
  //friend myDate operator -(int num, const myDate &date);

public:
    myDate(int year = 1582, int month = 1, int day = 1);
    int getDayOfMonth() const;
    int getMonth() const;
    int getYear() const;
    void setDayOfMonth(int day);
    void setMonth(int month);
    void setYear(int year);
    void setDate(int year, int month, int day);
    bool isLeapYear() const; //윤년
    bool isLeapYear(int y)const;
    int getDayOfWeek() const; //0=Sunday, 1=Monday, ..., 6=Saturday
    int getDayOfYear() const; //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
    int getNumHolidays() const; //휴일수 계산
    int getNumSummerTimeDays()const; //써머타임 날짜수
    void printCalendarOfMonth() const; // 달력출력하기
    int getDayOfWeek(int y, int m, int d) const;
    int getDayOfMonth1()const;
    int getDayOfMonth1(int y,int m)const;
    int operator -(const myDate &date)const;
    myDate operator +(int num)const;
    myDate operator -(int num)const;
    myDate& operator ++();  // prefix increment
    myDate& operator --();  // prefix decrement
    myDate  operator ++(int);   // postfix increment
    myDate  operator --(int);   // postfix decrement
    myDate& operator =(const myDate& date);
    myDate& operator  +=(int num);
    myDate& operator  -=(int num);
    bool operator >(const myDate& date) const;
    bool operator >=(const myDate& date) const;
    bool operator <(const myDate& date) const;
    bool operator <=(const myDate& date) const;
    bool operator ==(const myDate& date) const;
    bool operator !=(const myDate& date) const;
private:
    // information hiding : implement as you wish
    int year;
    int month;
    int day;
};
