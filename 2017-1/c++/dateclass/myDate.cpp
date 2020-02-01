#include "myDate.h"

myDate::myDate(int y,int m,int d){
    year = y;
    month = m;
    day = d;
}
int myDate::getDayOfMonth() const{
    return day;
}
int myDate::getMonth() const{
    return month;
}
int myDate::getYear() const{
    return year;
}
void myDate::setDayOfMonth(int day){
    this->day = day;
}
void myDate::setMonth(int month){
    this->month = month;
}
void myDate::setYear(int year){
    this->year = year;
}
void myDate::setDate(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
}
bool myDate::isLeapYear() const{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
bool myDate::isLeapYear(int y)const{
  return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}
int myDate::getDayOfMonth1()const{
  int resultday;
  switch (month){
    case 4:
    case 6:
    case 9:
    case 11:
      resultday = 30;
    break;
  case 2:
    if (isLeapYear())
      resultday = 29;
    else
      resultday = 28;
  break;
  default:
    resultday = 31;
  break;
  }
  return resultday;
}
int myDate::getDayOfMonth1(int y,int m)const{
  int resultday;
  switch (m){
    case 4:
    case 6:
    case 9:
    case 11:
      resultday = 30;
    break;
  case 2:
    if (isLeapYear(y))
      resultday = 29;
    else
      resultday = 28;
  break;
  default:
    resultday = 31;
  break;
  }
  return resultday;
}
int myDate::getDayOfWeek() const{
    int resultday=5;

    for (int i=1582; i < year; i++){
        if(isLeapYear(i))
            resultday += 366;
        else
            resultday += 365;
        resultday%=7;
    }
    for (int i=1; i<month; i++){
        switch (i){
          case 4:
          case 6:
          case 9:
          case 11:
            resultday += 30;
          break;
        case 2:
          if (isLeapYear())
            resultday += 29;
          else
            resultday += 28;
        break;
        default:
          resultday += 31;
        break;
      }
      resultday%=7;
    }

    resultday+=day-1;

    return resultday % 7;
}
int myDate::getDayOfWeek(int y, int m, int d) const{
    int resultday=5;

    for (int i=1582; i < y; i++){
        if(isLeapYear(i))
            resultday += 366;
        else
            resultday += 365;
        resultday%=7;
    }
    for (int i=1; i<m; i++){
        switch (i){
          case 4:
          case 6:
          case 9:
          case 11:
            resultday += 30;
          break;
        case 2:
          if (isLeapYear())
            resultday += 29;
          else
            resultday += 28;
        break;
        default:
          resultday += 31;
        break;
      }
      resultday%=7;
    }

    resultday+=d-1;

    return resultday % 7;
}
int myDate::getDayOfYear() const{
  int resultday = 1;
  for (int i=1; i<month; i++){
      switch (i){
        case 4:
        case 6:
        case 9:
        case 11:
          resultday += 30;
        break;
      case 2:
        if (isLeapYear())
          resultday += 29;
        else
          resultday += 28;
      break;
      default:
        resultday += 31;
      break;
    }
  }
  resultday+=day-1;
  return resultday;
}
int myDate::getNumHolidays()const{
  //1.1 3.1 5.5 6.6 7.17 8.15 10.3 12.25
  //2.1 2.2 2.3 5.15 9.15 9.16 9.17
  int firstday=5;
  int count=15;
  int yearday;
  if(isLeapYear())
    yearday = 366;
  else
    yearday = 365;
    // 해당 연의 총 일수
  for (int i=1582; i < year; i++){
      if(isLeapYear(i))
          firstday += 366;
      else
          firstday += 365;
  }
  firstday%=7; //해당 연 1월1일

  for(int i=0; i<yearday; i++){
    if((firstday+i)%7==6 || (firstday+i)%7 == 0)
      count++;
  }

  int reday=getDayOfWeek(year,1,1);
  if(reday==6 || reday==0)
    count--;

  reday=getDayOfWeek(year,3,1);
  if(reday==6 || reday==0)
   count--;
  reday = getDayOfWeek(year,5,5);
  if(reday==6 || reday==0)
   count--;
  reday = getDayOfWeek(year,6,6);
  if(reday==6 || reday==0)
   count--;
  reday = getDayOfWeek(year,7,17);
  if(reday==6 || reday==0)
   count--;
  reday = getDayOfWeek(year,8,15);
  if(reday==6 || reday==0)
   count--;
  reday = getDayOfWeek(year,10,3);
  if(reday==6 || reday==0)
   count--;
  reday = getDayOfWeek(year,12,25);
  if(reday==6 || reday==0)
   count--;
  reday = getDayOfWeek(year,2,1);
  if(reday==6 || reday==0)
   count--;
  reday = getDayOfWeek(year,2,2);
  if(reday==6 || reday==0)
   count--;
  reday =  getDayOfWeek(year,2,3);
  if(reday==6 || reday==0)
   count--;
  reday =  getDayOfWeek(year,5,15);
  if(reday==6 || reday==0)
   count--;
  reday =  getDayOfWeek(year,9,15);
  if(reday==6 || reday==0)
   count--;
  reday =  getDayOfWeek(year,9,16);
  if(reday==6 || reday==0)
   count--;
  reday =  getDayOfWeek(year,9,17);
  if(reday==6 || reday==0)
   count--;

  return count;
}
int myDate::getNumSummerTimeDays()const{
  int count = 183;
  int marchlast = getDayOfWeek(year, 3, 31);
  int octberlast = getDayOfWeek(year, 10, 31);
  for(int i=6; i>=0; i--){
    if(marchlast - i == 0)
      count+=i;
    if(octberlast - i ==0)
      count+=31-i;
  }
  return count;
}
void myDate::printCalendarOfMonth()const{
  int numdate = getDayOfWeek(year,month,1);
  int firstdate=1;
  cout<<year<<" "<<month<<endl;
  for(int l=0; l<numdate; l++){
    cout<<0<<" ";
  }
  if(isLeapYear(year)){
    for(int k=0; k<getDayOfMonth1(); k++){
      cout<<firstdate<<" ";
      firstdate++;
      numdate++;
      if(numdate%7==0)
        {cout<<endl;}
      }
    }
  else{
    for(int k=0; k<getDayOfMonth1(); k++){
      cout<<firstdate<<" ";
      firstdate++;
      numdate++;
      if(numdate%7==0)
        {cout<<endl;}

      }
    }
  if(numdate%7!=0){
    for(int l=0; l<(7-numdate%7); l++){
      cout<<0<<" ";
    }
    cout<<endl;
  }
}
ostream& operator<<(ostream &outstream, const myDate &date){
  if(date.day/10==0)
    outstream<<"0"<<date.day<<"/";
  else
    outstream<<date.day<<"/";
  if(date.month/10==0)
    outstream<<"0"<<date.month<<"/";
  else
    outstream<<date.month<<"/";

  outstream<<date.year;

  return outstream;
}
istream& operator>>(istream &instream,myDate &date){
  int y,m,d;
  instream>>y>>m>>d;
  date.setDate(y,m,d);
  return instream;
}
myDate operator +(int num, const myDate &date){
  myDate date1;
  date1.setDate(date.year,date.month,date.day);
  date1.day+=num;
  int maxdate = date1.getDayOfMonth1();
  while(maxdate<date1.day){
      date1.month++;
      date1.day-=maxdate;
    if(date1.month>12){
      date1.year++;
      date1.month=1;
    }
    maxdate = date1.getDayOfMonth1();
  }
  while(date1.day<=0){
    date1.month--;
    if(date1.month<=0){
      date1.year--;
      date1.month = 12;
    }
    maxdate = date1.getDayOfMonth1();
    date1.day+=maxdate;
  }
  return date1;
}
int myDate::operator -(const myDate &date)const{
  int a=5,b=5;
  for(int i=1582; i<year; i++){
    if(isLeapYear(i))
      a+=366;
    else
      a+=365;
  }
  for(int i=1582; i<date.year; i++){
    if(isLeapYear(i))
      b+=366;
    else
      b+=365;
  }
  for(int i=1; i<month; i++){
    a+=getDayOfMonth1(year,i);
  }
  for(int i=1; i<date.month; i++){
    b+=getDayOfMonth1(date.year,i);
  }
  a+=day-1;
  b+=date.day-1;

  return a-b;
}
myDate myDate::operator +(int num)const{
  myDate date1;
  date1.setDate(this->year,this->month,this->day);
  date1.day+=num;
  int maxdate = date1.getDayOfMonth1();
  while(maxdate<date1.day){
      date1.month++;
      date1.day-=maxdate;
    if(date1.month>12){
      date1.year++;
      date1.month=1;
    }
    maxdate = date1.getDayOfMonth1();
  }
  while(date1.day<=0){
    date1.month--;
    if(date1.month<=0){
      date1.year--;
      date1.month = 12;
    }
    maxdate = date1.getDayOfMonth1();
    date1.day+=maxdate;
  }
  return date1;
}
myDate myDate::operator -(int num)const{
  myDate date1;
  date1.setDate(this->year,this->month,this->day);
  date1.day-=num;
  int maxdate = date1.getDayOfMonth1();
  while(maxdate<date1.day){
      date1.month++;
      date1.day-=maxdate;
    if(date1.month>12){
      date1.year++;
      date1.month=1;
    }
    maxdate = date1.getDayOfMonth1();
  }
  while(date1.day<=0){
    date1.month--;
    if(date1.month<=0){
      date1.year--;
      date1.month = 12;
    }
    maxdate = date1.getDayOfMonth1();
    date1.day+=maxdate;
  }
  return date1;
}
myDate& myDate::operator ++(){
  day++;
  int maxdate = getDayOfMonth1();
  if(day>maxdate){
    day-=maxdate;
    month++;
  }
  if(month>12){
    year++;
    month=1;
  }
  return *this;
}
myDate& myDate::operator --(){
  day--;
  if(day<=0){
    month--;
    if(month<=0){
      year--;
      month=12;
    }
    int maxdate = getDayOfMonth1();
    day+=maxdate;
  }

  return *this;
}
myDate myDate::operator ++(int){
  myDate date1;
  date1.setDate(this->year,this->month,this->day);
  day++;
  int maxdate = getDayOfMonth1();
  if(day>maxdate){
    day-=maxdate;
    month++;
  }
  if(month>12){
    year++;
    month=1;
  }
  return date1;
}
myDate myDate::operator --(int){
  myDate date1;
  date1.setDate(this->year,this->month,this->day);
  day--;
  if(day<=0){
    month--;
    if(month<=0){
      year--;
      month=12;
    }
    int maxdate = getDayOfMonth1();
    day+=maxdate;
  }
  return date1;
}
myDate& myDate::operator =(const myDate& date){
  this->year = date.year;
  this->month = date.month;
  this->day = date.day;
  return *this;
}
myDate& myDate::operator +=(int num){
  day+=num;
  int maxdate = getDayOfMonth1();
  while(maxdate<day){
    month++;
    day-=maxdate;
    if(month>12){
      year++;
      month=1;
    }
    maxdate = getDayOfMonth1();
  }
  while(day<=0){
    month--;
    if(month<=0){
      year--;
      month=12;
    }
    maxdate = getDayOfMonth1();
    day+=maxdate;
  }
  return *this;
}
myDate& myDate::operator -=(int num){
  day-=num;
  int maxdate = getDayOfMonth1();
  while(maxdate<day){
    month++;
    day-=maxdate;
    if(month>12){
      year++;
      month=1;
    }
    maxdate = getDayOfMonth1();
  }
  while(day<=0){
    month--;
    if(month<=0){
      year--;
      month=12;
    }
    maxdate = getDayOfMonth1();
    day+=maxdate;
  }
  return *this;
}
bool myDate::operator >(const myDate& date)const{
  if(year>date.year)
    return true;
  else if(year<date.year)
    return false;
  else if(month>date.month)
    return true;
  else if(month<date.month)
    return false;
  else if(day>date.day)
    return true;
  else
    return false;
}
bool myDate::operator >=(const myDate& date)const{
  return !(*this<date);
}
bool myDate::operator <(const myDate& date)const{
  if(year<date.year)
    return true;
  else if(year>date.year)
    return false;
  else if(month<date.month)
    return true;
  else if(month>date.month)
    return false;
  else if(day<date.day)
    return true;
  else
    return false;
}
bool myDate::operator <=(const myDate& date)const{
  return !(*this>date);
}
bool myDate::operator ==(const myDate& date)const{
  return ((year==date.year) && (month== date.month) && (day== date.day));
}
bool myDate::operator !=(const myDate& date)const{
  return !(*this==date);
}
