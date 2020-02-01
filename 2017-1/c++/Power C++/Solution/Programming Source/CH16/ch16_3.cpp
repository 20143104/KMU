#include <iostream>
#define MAX 10

using namespace std;

class Stack
{
	int sta[MAX];
	int index;
public:
	Stack()
	{
		index = 0;
		for(int i=0; i < MAX; i++)
			sta[i] = 0;
	}
	void push(int a)
	{
		if(index > MAX) throw "Stack Overflow";
		
		sta[index] = a;
		index++;		
	}
	void pop()
	{
		index--;
		if(index < 0) throw "Stack Underflow";
		sta[index] = 0;
			
	}
	void display()
	{
		cout<<"------------------------------------------------------------------"<<endl;
		for(int i=0; i < index ; i++)
		{
 			cout<<"스택"<<"["<<i<<"]"<<"에 저장된값은 :" << sta[i] <<endl;	
		}
		cout<<"------------------------------------------------------------------"<<endl;
	}
};

int main()
{
	Stack s;
	
	try{
		s.push(3);
		s.display();
		s.push(4);
		s.display();
		s.pop();
		s.display();
		s.pop();
		s.display();
		s.pop();
		//s.display();
	}

	catch(char *e)
	{
		cout<<e<<endl;
	}
	return 0;
}