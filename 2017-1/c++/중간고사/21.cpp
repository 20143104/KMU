/******************************************************************************
*problem : 요일계산하기                                           *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/

#include<iostream>
#include<fstream>

using namespace std;

int isspecialyear(int n);
int maxdate(int n);
int smaxdate(int n);
int main(){
  ifstream instream;
  instream.open("input.txt");
  if(instream.fail()){
   cerr<<"input file opening failed.\n";
  }
  int numtestcases;

  instream>>numtestcases;

  for(int i=0; i<numtestcases; i++){
    int year,month,date;
    int numdate=5;
    instream>>year>>month>>date;

    for(int k=1582; k<year; k++){
      if(isspecialyear(k))
        {numdate+=366;}
      else
        {numdate+=365;}
      numdate%=7;
    }


    for(int k=1; k<month; k++){
      if(isspecialyear(year)){
        numdate+=(smaxdate(k));
      }
      else{
        numdate+=(maxdate(k));
      }

      numdate%=7;
    }
    numdate+=(date-1);
    numdate%=7;
    cout<<numdate<<endl;
  }
  instream.close();
  return 0;
}

int isspecialyear(int n){
 if(n%400==0){
    return 1;
 }
 else if(n%100==0){
    return 0;
 }
 else if(n%4==0){
    return 1;
 }
 else{
    return 0;
 }
}
int maxdate(int n){
  switch(n){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
      break;
    case 2:
      return 28;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
      break;
  }
}
int smaxdate(int n){
  switch(n){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
      break;
    case 2:
      return 29;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
      break;
  }
}
