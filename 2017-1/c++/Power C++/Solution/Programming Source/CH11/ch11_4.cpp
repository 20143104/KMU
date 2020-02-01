#include <iostream>

using namespace std;

class Counter
{
private:
	int value;
public:
	const int getValue() const
	{
		return value;
	}
	const void setValue(int const value)
	{
		this->value = value;
	}
	const void print() const
	{
		cout<<value<<endl;
	}
	const void countDown()
	{
		cout<<"카운트 감소 : ";
		value--;
	}
	const void countUp()
	{
		cout<<"카운트 증가 : ";
		value++;
	}
};

void main()
{
	Counter st;

	st.setValue(10);
	st.print();
	st.countDown();
	st.print();
	st.countDown();
	st.print();
	st.countDown();
	st.print();
	st.countUp();
	st.print();
	st.countUp();
	st.print();

}