#include <iostream>
#include <string>

using namespace std;

template<typename T, typename T2>
class Pair
{
private:
	T first;
	T2 second;
public:
	Pair(T,T2);
	void setFirst(T f);
	void setSecond(T2 s);
	T getFirst();
	T2 getSecond();
};

template<typename T, typename T2>
Pair<T,T2>::Pair(T f, T2 s)
{
	first = f;
	second = s;
}

template<typename T, typename T2>
void Pair<T,T2>::setFirst(T f)
{
	first = f;
}

template<typename T, typename T2>
void Pair<T,T2>::setSecond(T2 f)
{
	second = s;
}

template<typename T, typename T2>
T Pair<T,T2>::getFirst()
{
	return first;
}

template<typename T, typename T2>
T2 Pair<T,T2>::getSecond()
{
	return second;
}

int main(void)
{
	Pair<int,int> p1(1,2);
	Pair<int,double> p2(3,4.5);
	Pair<double,int> p3(6.7,8);
	Pair<double,double> p4(9.1,2.3);

	cout<<p1.getFirst()<<" , "<<p1.getSecond()<<endl;
	cout<<p2.getFirst()<<" , "<<p2.getSecond()<<endl;
	cout<<p3.getFirst()<<" , "<<p3.getSecond()<<endl;
	cout<<p4.getFirst()<<" , "<<p4.getSecond()<<endl;

	return 0;
}