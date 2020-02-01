#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Employee
{
public:
	T getAverage(T value,T count)
	{
		return value/count;
	}
};

int main(void)
{
	Employee<int> e;
	cout<<"ЦђБе : "<<e.getAverage(100,4)<<endl;
	return 0;
}
