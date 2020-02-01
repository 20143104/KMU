#include <iostream>
#include <assert.h>

using std::ostream;
using std::istream;
using std::endl;
using std::cout;
using std::cin;


class Array 
{
	friend ostream& operator<<(ostream &, const Array &);
private:
	int *data;
	int size;
public:
	Array(int size = 10);
	~Array();
	int getSize() const;
	Array& operator=(const Array &a);
	int& operator[](int i);
	bool Array::operator!=(const Array& a);
	bool Array::operator==(const Array& a);
};

Array::Array(int s) {
	size = (s > 0 ? s : 10);
	data = new int[size];
	
	for(int i = 0; i < size; i++)
		data[i] = 0;
}

Array::~Array() {
	delete [] data; 
	data = NULL;
}

Array& Array::operator=(const Array& a) {
	if (&a != this) {
		delete [] data;	
		size = a.size;
		data = new int[size];
		
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
	}
	return *this;
}

int Array::getSize() const 
{ 
	return size; 
}

bool Array::operator==(const Array& a) 
{ 
	int tot = 0;
	if(this->size != a.size)
	{
		return false;
	}

	for(int i=0; i <this->size ; i++)
	{
		for(int j=0; j<this->size; j++)
		{
			if( this->data[i] == a.data[j]){
				tot++;
				break;
			}
		}
	}
	if(tot == this->size)
		return true;
}
bool Array::operator!=(const Array& a) 
{ 
	int tot = 0;
	if(this->size != a.size)
	{
		return true;
	}
	
	for(int i=0; i <this->size ; i++)
	{
		for(int j=0; j<this->size; j++)
		{
			if( this->data[i] == a.data[j]){
				tot++;
				break;
			}
		}
	}
	if(tot != this->size)
		return true;
	return false;
}
int& Array::operator[](int index) {
	assert(0 <= index && index < size);	
	return data[index]; 
}


ostream& operator<<(ostream &output, const Array &a) {
	int i;
	for (i = 0; i < a.size; i++) {
		output << a.data[i] << ' ';
	}
	output << endl;
	return output;
}

int main()
{
	Array a1(10), a2(10), a3(10);
	
	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;

	a2[0] = 1;
	a2[1] = 2;
	a2[2] = 3;
	a2[3] = 4;

	a3 = a1;
	a3[3] = 5;
	cout<<"a1 배열은 : ";
	cout<<a1<<endl;
	cout<<"a2 배열은 : ";
	cout<<a2<<endl;
	cout<<"a3 배열은 : ";
	cout<<a3<<endl;
	cout<<"출력 연산자 >>을 중복 정의 : ";
	cout << a1<<endl;
 	cout<<"a1 == a2 을 중복 정의 : ";
 	cout << (a1 == a2) <<endl;	
	cout<<"a1 != a3 을 중복 정의 : ";
	cout << (a1 != a3) <<endl;	
	cout<<"a3 = a1 을 중복 정의 : ";
	a3 = a1;
	cout << a3 <<endl;	
	
	return 0;
}		
