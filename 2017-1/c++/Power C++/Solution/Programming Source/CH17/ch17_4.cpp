#include <iostream>
#include <ctime>
#define MAXSIZE 10

using namespace std;

template<typename T>
class List{
private:
	T data[MAXSIZE];
	int count;
public:
	List()
	{
		count = 0;
	}
	void Add(T d)
	{
		data[count] = d;
		count++;
		
	}
	T Select(int c)
	{
		return data[c];
	}
	int getCount()
	{
		return count;
	}
	
};



int main(void)
{
	int count;
	List<int> l;
	srand(time(NULL));
	l.Add(12);
	l.Add(52);
	l.Add(38);
	l.Add(87);
	l.Add(28);
	l.Add(10);
	cout<<"List »ðÀÔ ¿ø¼Ò : 12,52,38,87,28,10"<<endl;
	cout<<"·£´ý Ãâ·Â °ª : ";
	count = rand()%l.getCount();
	cout<<l.Select(count)<<endl;
	cout<<"·£´ý Ãâ·Â °ª : ";
	count = rand()%l.getCount();
	cout<<l.Select(count)<<endl;
	cout<<"·£´ý Ãâ·Â °ª : ";
	count = rand()%l.getCount();
	cout<<l.Select(count)<<endl;
	cout<<"·£´ý Ãâ·Â °ª : ";
	count = rand()%l.getCount();
	cout<<l.Select(count)<<endl;
	return 0;	
}
