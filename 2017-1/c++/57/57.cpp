#include <fstream>
#include <cstdlib>
#include "MyMatrix.h"
void testSimpleCase();
void testDataFromFile();
myMatrix readMatrix(ifstream& inStream);
int main(void)
{
    testSimpleCase();
    testDataFromFile();
}
void testSimpleCase()
{
    int testData1[6] = {1, 2, 3, 4, 5, 6};
    int testData2[6] = {6, 5, 4, 3, 2, 1};
    myMatrix m1(2, 2, 1);
    myMatrix m2(2, 3, testData1);
    myMatrix m3(3, 2, testData2);
    myMatrix m4(m3);
    myMatrix m5, m6(2,3,1), m7(3,4,1), m8(4,2,1), m9;
    cout << m1.getRows() << " " << m1.getCols() << endl;
    m4(0,0) = 1;
    m4(0,1) = 2;
    cout << m4[0][0] << " " << m4[0][1] << endl;
    cout << m4(1,0) << " " << m4(1,1) << endl;
    cout << m4[2][0] << " " << m4(2,1) << endl;
    m3 = m3;
    cout << m3;
    m5 = m3 + m4;
    cout << m5;

    cout << (m4 == m3) << " " << (m4 != m3) << endl;

    m4 = m5 - m4;
    cout << (m4 == m3) << " " << (m4 != m3) << endl;

    m9 = m6 * m7* m8+ m1;
    cout << m9;

    m8 = m7 = m6 = m5;
    cout << m8;

    m4 = m4 * 2;
    cout << m4;
    m4 = 2 * m4;
    cout << m4;
    m5 = m2 * m3;
    cout << m5;
    m2 *= m3;
    cout << m2;

    m2 += m1;
    cout << m2;

    m2 -= m1;
    cout << m2;

    m2 = -m1 + 2 * m2;
    cout << m2;

    m7 = m4;
    m8 = m7 * m4.transpose();

    cout << m8;

  }
void testDataFromFile()
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
for(int i=0; i<numTestCases; i++)
{
    myMatrix m[4], m0;
    for(int j=0; j<4; j++)
        m[j] = readMatrix(inStream);
    m0 = m[0] * m[1] * m[2] + m[3];
    cout << m0;
    cout << m0[0][0] << " " << m0[m0.getRows()-1][m0.getCols()-1] << endl;
}
inStream.close();
}
#define MAX_SIZE 10000  // 100 * 100
myMatrix readMatrix(ifstream& inStream)
{
int data[MAX_SIZE];
int row, col;
inStream >> row >> col;
for(int i=0; i<row*col; i++)
    inStream >> data[i];
return myMatrix(row, col, data);
}
