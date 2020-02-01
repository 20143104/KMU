#include <iostream>

using namespace std;

int main()
{
	double ac = 0, ae = 0, bc = 0, de = 0;

	

	cout<<"AC: ";
	cin>>ac;
	cout<<"AE: ";
	cin>>ae;
	cout<<"BC: ";
	cin>>bc;
	
	de = (ae*bc)/ac;

	cout<<"DE는 "<<de<<"입니다."<<endl;
	
		

	return 0;
}