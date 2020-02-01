#include "MyMatrix.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
// Constructor
myMatrix::myMatrix(int nRows, int nCols) :rows(nRows), cols(nCols),
pData(NULL)
{
    allocateMemory();
    for (int i = 0; i<rows; i++)
        for (int j = 0; j<cols; j++)
            pData[i][j] = 0;
}

myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows),cols(nCols),pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = initValue;
}
myMatrix::myMatrix(int nRows, int nCols, int *data) : rows(nRows),cols(nCols),pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = data[i*cols+j];
}
myMatrix::myMatrix(int nRows, int nCols, int **data) : rows(nRows), cols(nCols),
pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = data[i][j];
}
myMatrix::~myMatrix()
{
    if (pData != NULL)
        deleteMemory();
}
// Copy constructor
myMatrix::myMatrix(const myMatrix& mat) :rows(mat.rows), cols(mat.cols), pData(NULL)
{
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = mat.pData[i][j];
}
// Accessor functions
int myMatrix::getRows() const
{
    return rows;
}
int myMatrix::getCols() const
{
    return cols;
}
void myMatrix::allocateMemory()
{
    if (pData != NULL)
        deleteMemory();
    pData = new int * [rows];
    if(pData == NULL)
        errorMessage("Memory allocation error");
    pData[0] = new int [rows*cols];
    if(pData[0] == NULL)
    {
        delete [] pData;
        errorMessage("Memory allocation error");
    }
    for(int i=1; i<rows; i++)
        pData[i] = pData[0] + i * cols;
}
void myMatrix::deleteMemory()
{
    delete [] pData[0];
    delete [] pData;
    pData = NULL;
}
int* myMatrix::operator [](int i) const
{
    if((i < 0) || (i >= rows))
        errorMessage("Accessing out-of-bound value of a matrix");
    return pData[i];
}
int& myMatrix::operator ()(int i, int j) const
{
  if((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
    errorMessage("Accessing out-of-bound value of a matrix");
  return pData[i][j];
}
// Overloaded binary operators
myMatrix myMatrix::operator +(const myMatrix& mat) const
{
  if ((rows != mat.rows) || (cols != mat.cols))
    errorMessage("cannot add two matrices of different size");
  myMatrix add(rows,cols);
  for(int i=0; i<rows; i++)
    for(int j=0; j<cols; j++)
      add.pData[i][j]=pData[i][j]+mat.pData[i][j];

  return add;
}
myMatrix myMatrix::operator -(const myMatrix& mat) const
{
  if ((rows != mat.rows) || (cols != mat.cols))
    errorMessage("cannot do subtraction between two matrices of different size");
  myMatrix sub(rows,cols);
  for(int i=0; i<rows; i++)
    for(int j=0; j<cols; j++)
      sub.pData[i][j]=pData[i][j]-mat.pData[i][j];
  return sub;
}

myMatrix myMatrix::operator *(const myMatrix& mat) const
{
  if (cols != mat.rows)
    errorMessage("cannot do multiplication between the given two matrices");
  myMatrix multi(rows,mat.cols);
  for(int i=0; i<rows; i++){
    for(int j=0; j<mat.cols; j++){
      int sum=0;
      for(int k=0; k<cols; k++)
        sum+=pData[i][k]*mat.pData[k][j];
      multi.pData[i][j]=sum;
    }
  }
  return multi;
}

myMatrix myMatrix::operator *(int value) const
{
  myMatrix mat = *this;
  for(int i=0; i<rows; i++)
    for(int j=0; j<cols; j++)
      mat.pData[i][j]=value*pData[i][j];
  return mat;
}
// Assignment operators

myMatrix& myMatrix::operator =(const myMatrix& mat)
{
  if(&mat == this)
    return *this;

  this->rows = mat.rows;
  this->cols = mat.cols;
  allocateMemory();
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      this->pData[i][j] = mat.pData[i][j];
    }
  }
  return *this;
}

myMatrix& myMatrix::operator +=(const myMatrix& mat)
{
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      pData[i][j]+=mat.pData[i][j];
    }
  }
  return *this;
}
myMatrix& myMatrix::operator -=(const myMatrix& mat)
{
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      pData[i][j]-=mat.pData[i][j];
    }
  }
  return *this;
}
myMatrix& myMatrix::operator *=(const myMatrix& mat)
{
  myMatrix multi(rows,mat.cols);
  for(int i=0; i<rows; i++){
    for(int j=0; j<mat.cols; j++){
      int sum=0;
      for(int k=0; k<cols; k++){
        sum+=pData[i][k]*mat.pData[k][j];
      }
      multi.pData[i][j]=sum;
    }
  }
  *this=multi;
  return *this;
}
myMatrix& myMatrix::operator *=(int value)
{
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      pData[i][j]*=value;
    }
  }
  return *this;
}
// Overloading relational operators

bool myMatrix::operator ==(const myMatrix& mat) const
{
  if ((rows != mat.rows) || (cols != mat.cols))
    return false;
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(pData[i][j]!=mat.pData[i][j])
        return false;
    }
  }
  return true;
}
bool myMatrix::operator !=(const myMatrix& mat) const
{
    return !((*this) == mat);
}
// Overloaded unary operators

myMatrix myMatrix::operator -() const       // unary minus
{
  myMatrix mat(*this);
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      mat.pData[i][j]*=-1;
    }
  }
  return mat;
}
// transpose the matrix

myMatrix& myMatrix::transpose()
{
  myMatrix mat(cols,rows);
  for(int i=0; i<cols; i++){
    for(int j=0; j<rows; j++){
      mat.pData[i][j] = pData[j][i];
    }
  }
  *this = mat;
  return *this;
}
// private functions

void myMatrix::errorMessage(string str) const
{
    cout << "Error: " << str << endl;
    exit(1);
}
// friend functions

myMatrix operator *(int value, const myMatrix& mat)
{
  return mat*value;
}

ostream &operator <<(ostream &outStream, const myMatrix& mat)
{
    outStream << mat.rows << "*" << mat.cols << endl;
    for(int i=0; i<mat.rows; i++)
    {
        for (int j=0; j<mat.cols; j++)
            outStream << mat[i][j] << " ";
        outStream << endl;
    }
    return outStream;
}
istream &operator >>(istream &inStream, myMatrix& mat)
{
    mat.deleteMemory();
    inStream >> mat.rows >> mat.cols;
    mat.allocateMemory();
    for(int i=0; i<mat.rows; i++)
    {
        for (int j=0; j<mat.cols; j++)
            inStream >> mat[i][j];
    }
    return inStream;
}
