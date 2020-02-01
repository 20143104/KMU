#include <iostream>
#include <assert.h>
using namespace std;

class SafeArray
{
	int *data;
	int size;
public:
	SafeArray(int s)
	{
		size = (s > 0 ? s: 10);
		data = new int[size];

		for(int i = 0; i<size; i++)
			data[i] = 0;
	}
	SafeArray& SafeArray::operator=(const SafeArray& a)
	{
		if (&a != this){
			delete [] data;
			size = a.size;
			data = new int[size];

			for(int i=0; i <size; i++)
				data[i] = a.data[i];
		}
		return *this;
	}	
	int& operator[](int index)
	{
		if(0 > index || index > size) throw "IndexException" ;
		return data[index];
	}

};
int main()
{
	try{
		SafeArray sa(10);
		sa[0] = 1;
		sa[1] = 2;
		sa[2] = 3;
		sa[3] = 4;
		sa[22] = 5;
	}
	catch(char *e)
	{
		cout<<e<<endl;
	}
	return 0;
}