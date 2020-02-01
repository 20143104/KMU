#include <iostream>
#include <string>

using namespace std;

class MyArray{
private:
	int size;
	int *ptr;
	int value;
public:
	MyArray()
	{
		size = 0;
		ptr = &value;
	}
	~MyArray(){

	}
	void append(int i)
	{
		ptr[size] = i;
		size++;
	}
	void Delete()
	{
		ptr[size] = 0;
		size--;
	}
	void print()
	{
		for(int i = 0;i < size;i++){
			cout<<ptr[i]<<endl;
		}
	}
};

int main()
{
	MyArray array;
	
	array.append(11);
	array.append(22);
	array.append(33);
	array.append(44);
	array.append(55);
	array.append(66);
	array.print();
	array.Delete();
	array.print();

	return 0;
}
