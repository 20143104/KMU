#include <iostream>
#include <fstream>
#include <cstdlib>
#include "myDate.h"
using namespace std;

const int MAX_SIZE = 100;
int testSimpleCase();
void testDataFromFile();
const myDate& getMinDate(const myDate dates[], int n);
const myDate& getMaxDate(const myDate dates[], int n);
void sortDates(myDate dates[], int n);
void swap(myDate &d1, myDate &d2);

int main(){
    testSimpleCase();
    testDataFromFile();
    return 0;
}
int testSimpleCase()
{
    myDate d1, d2(99999,12,31), d3(2008,2,20);
    myDate d4, d5, d6, d7, d8, d9(d3);
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << d9 << endl;
    cout << d3 - d1 << endl;
    d4 = d5 = d6 = d7 = d8 = d9;
    cout << ++d7 + 365 << " " << d7 << endl;
    cout << d7++ + 365 << " " << d7 << endl;
    cout << --d7 - 365 << " " << d7 << endl;
    cout << d7-- - 365 << " " << d7 << endl;
    cout << -365 + d7 << " " << d7 << endl;
    d4.setDate(2999, 12, 31);
    d5.setDate(2000, 1, 1);
    d6.setDate(3000, 1, 1);
    d6 += d5 - d4;
    cout << d6 << endl;

    d6 -= d5 - d4;
    cout << d6 << endl;

    cout << (d6 == d8) << " " << (d6 != d8) << endl;
    cout << (d7 == d8) << " " << (d7 != d8) << endl;
    cout << (d6 >= d8) << " " << (d6 > d8) << endl;
    cout << (d6 <= d8) << " " << (d6 < d8) << endl;
    cout << (d7 >= d8) << " " << (d7 > d8) << endl;
    cout << (d7 <= d8) << " " << (d7 < d8) << endl;

}
void testDataFromFile()
{
    ifstream inStream;
    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    int numtestcases;
    inStream >> numtestcases;
    for(int i=0; i<numtestcases; i++)
    {
        myDate dates[MAX_SIZE], minDate, maxDate;
        int numData;
        inStream >> numData;
        for(int j=0; j<numData; j++)
          inStream>>dates[j];
        minDate = getMinDate(dates, numData);
        maxDate = getMaxDate(dates, numData);
        cout << minDate << " " << maxDate << " " << maxDate - minDate << endl;

        sortDates(dates, numData);
        for(int j=0; j<numData; j++)
            cout << dates[j] << " ";
        cout << endl;
    }
    inStream.close();
}
//날짜중에서가장이른날짜를계산함
const myDate& getMinDate(const myDate dates[], int n)
{
    int min = 0;
    for(int i=1; i<n; i++)
    {
        if (dates[min] > dates[i])
            min = i;
    }
    return dates[min];
}
//날짜중에서가장늦은날짜를계산함
const myDate& getMaxDate(const myDate dates[], int n)
{
    int max = 0;
    for(int i=1; i<n; i++)
    {
        if (dates[max] < dates[i])
            max = i;
    }
    return dates[max];
}
///날짜를오름차순으로정렬함//
void sortDates(myDate dates[], int n)
{
    for(int i=n-2; i>=0; i--)
        for(int j=0; j<=i; j++)
            if(dates[j] > dates[j+1])
                swap(dates[j], dates[j+1]);
}
//두날짜를서로바꿈
void swap(myDate &d1, myDate &d2)
{
    myDate tmp;
    tmp = d1;
    d1  = d2;
    d2  = tmp;
}
