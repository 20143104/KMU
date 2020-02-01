/******************************************************************************
*problem : dateclass 1                                       *
*                                                                             *
******************************************************************************/

/******************************************************************************
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년                         *
 *                                                          20143104 조승현   *
 * ***************************************************************************/
 #include <iostream>
 #include <fstream>
 #include <cstdlib>
 #include "myDate.h"
 using namespace std;
 int main(int argc,char *argv[])
 {
     ifstream inStream;
     int numTestCases;
     inStream.open("input.txt");
     if (inStream.fail())
     {
         cerr << "Input file opening failed.\n";
         exit(1);
     }
     inStream >> numTestCases;
     for (int i = 0; i<numTestCases; i++)
     {
         int year, month, day;
         inStream >> year >> month >> day;
         myDate date(year, month, day);
         cout<<date.getDayOfYear()<<" ";
         cout<<datd.getNumHolidays()<<endl;
     }
     inStream.close();
 }
