#include "MyPolynomial.h"
/********************* add your code here ********************************/
myPolynomial::myPolynomial(int c, unsigned e){
  degree = e;
  nterms = 1;
  terms[0]= myTerm(c,e);
}
myPolynomial::myPolynomial(int nTerms, int mono[]){
  degree = mono[2*nTerms-1];
  nterms = nTerms;
  int pos=0;
  for(int i=0; i<2*nTerms; i+=2)
    terms[pos++]=myTerm(mono[i],mono[i+1]);
}
myPolynomial::myPolynomial(const myPolynomial &poly){
  degree = poly.degree;
  for(int i=0; i<degree; i++)
    terms[i] = poly.terms[i];
}
//////////////////////////bool operator////////////////////////////////
bool myPolynomial::operator ==(const myPolynomial &poly)const{
  if(degree != poly.degree)
    return false;
  for(int i=0; i<nterms; i++){
    if(terms[i]!=poly.terms[i])
      return false;
  }
  return true;
}
bool myPolynomial::operator !=(const myPolynomial &poly)const{
  return !(*this==poly);
}
/////////////////operator/////////////////////////////////////////
myPolynomial myPolynomial::operator -() const{
  myPolynomial tmp(*this);
  for(int i=0; i<nterms; i++){
    tmp.terms[i].coeff*=-1;
  }
  return tmp;
}
myPolynomial myPolynomial::operator *(int k) const{
  myPolynomial tmp(*this);
  for(int i=0; i<nterms; i++){
    tmp.terms[i].coeff*=k;
  }
  return tmp;
}
/*
myPolynomial myPolynomial::operator +(const myPolynomial &poly) const{
  myPolynomial tmp(*this);
  i
  int apos=0,bpos=0;
  while(apos<nterms && bpos<poly.nterms){
    if(terms[apos].exp == poly.nterms[bpos].exp){
      int t= terms[apos].coeff + poly.nterms[bpos].coeff;
      tmp.terms[apos].coeff = t;
      apos++; bpos++;
    }
    else if(terms[apos].exp < poly.nterms[bpos].exp){
      tmp.terms[]
    }
  }
}
*/

// output operator

ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
    if (poly == myPolynomial::ZERO)
        return outStream << 0;
    else if (poly == myPolynomial:: ONE)
        return outStream << 1;
    else if( poly == myPolynomial:: X)
        return outStream<< 'X';
/********************* add your code here *******************************/
    //return outStream;
}

const myPolynomial myPolynomial::ZERO(0);
// the zero polynomialP(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0);  // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1);
// the monomial P(x) = x
