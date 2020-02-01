#include <iostream>
#define MAXSIZE 10

using namespace std;

template<typename T>
class Queue{
private:
	T data[MAXSIZE];
	int count;
public:
	Queue()
	{
		count = 0;
	}
	void enqueue(T d)
	{
		data[count] = d;
		count++;
	}
	T dequeue()
	{
		T d;
		d = data[0];
		for(int i = 0;i < count;i++){
			data[i] = data[i+1];
		}
		return d;
	}
	
};

int main(void)
{
	Queue<int> q;
	cout<<"Queue »ðÀÔ µ¥ÀÌÅÍ : 34,26,68,20,24,23"<<endl;
	q.enqueue(34);
	q.enqueue(26);
	q.enqueue(68);
	q.enqueue(20);
	q.enqueue(24);
	q.enqueue(23);
	cout<<"q.dequeue() : "<<q.dequeue()<<endl;
	cout<<"q.dequeue() : "<<q.dequeue()<<endl;
	cout<<"q.dequeue() : "<<q.dequeue()<<endl;
	cout<<"q.dequeue() : "<<q.dequeue()<<endl;
	cout<<"q.dequeue() : "<<q.dequeue()<<endl;
	cout<<"q.dequeue() : "<<q.dequeue()<<endl;
	
	return 0;	
}
