#include <iostream>

using namespace std;

class Fraction
{
	int numer;
	int denom;
public:
	Fraction()
	{
		this->numer = 1;
		this->denom = 1;	
	}
	Fraction(int numer, int denom)
	{
		this->numer = numer;
		this->denom = denom;	
	}
	~Fraction(){}
	Fraction operator+(Fraction f)
	{
		Fraction c;

		if( this->denom == f.denom){
			c.numer = this->numer + f.numer;
			c.denom = this->denom;
		}
		else
		{
			int n = (this->denom * f.numer) + (f.denom * this->numer);
			c.numer = n;
			int d = this->denom * f.denom;
			c.denom = d;
		}
		return c;
	}
	void display()
	{
		cout<<numer<<"/"<<denom<<endl;
	}
};
int main()
{
	Fraction a(3, 8);
	Fraction b(1, 8);
	Fraction c;
	c = a + b;
	cout<<"a = ";
	a.display();
	cout<<"b = ";
	b.display();
	cout<<"a + b = ";
	c.display();

	return 0;
}