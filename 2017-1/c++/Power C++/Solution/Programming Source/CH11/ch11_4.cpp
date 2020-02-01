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
		cout<<"ī��Ʈ ���� : ";
		value--;
	}
	const void countUp()
	{
		cout<<"ī��Ʈ ���� : ";
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