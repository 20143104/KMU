#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_
#include <iostream>
#include <string>
using namespace std;
class myMatrix
{
public:
    // friend 함수
    friend myMatrix operator *(int value, const myMatrix& mat);
    friend ostream &operator <<(ostream &outStream, const myMatrix& mat);
    friend istream &operator >> (istream &inStream, myMatrix& mat);
    // Constructor (생성자)
    myMatrix(int nRows = 1, int nCols = 1);
    myMatrix(int nRows, int nCols, int initValue);
    myMatrix(int nRows, int nCols, int *data);
    myMatrix(int nRows, int nCols, int **data);
    // Copy constructor (복사생성자)
    myMatrix(const myMatrix& mat);
    // Destructor (소멸자)
    ~myMatrix();
    // Accessor functions (접근자)
    int getRows() const;
    int getCols() const;
    int* operator [](int i) const;
    int& operator ()(int i, int j) const;
    // Overloaded binary operators
    myMatrix operator +(const myMatrix& mat) const;
    myMatrix operator -(const myMatrix& mat) const;
    myMatrix operator *(const myMatrix& mat) const;
    myMatrix operator *(int value) const;
    // Overloaded assignment operators
    myMatrix& operator =(const myMatrix& mat);
    myMatrix& operator +=(const myMatrix& mat);
    myMatrix& operator -=(const myMatrix& mat);
    myMatrix& operator *=(const myMatrix& mat);
    myMatrix& operator *=(int value);
    // Overloading relational operators
    bool operator ==(const myMatrix& mat) const;
    bool operator !=(const myMatrix& mat) const;
    // Overloaded unary operators
    myMatrix operator -() const;    // unary minus
    // transpose the matrix
    myMatrix& transpose();
private:
    int rows;           // number of rows
    int cols;           // number of columns
    int **pData;            // pointer to actual data
    void allocateMemory();  // allocate memory for pDdata
    void deleteMemory();        // delete memory for pData
    void errorMessage(string msg) const;    // print error message and exit
};
#endif
