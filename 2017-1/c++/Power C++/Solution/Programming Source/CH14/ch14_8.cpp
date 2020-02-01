#include <iostream>
#include <string>

using namespace std;

class Book 
{
protected:
	int number; 
	string title; 
	string author; 
	
public:
	Book(int n, string t, string a) 
	{
		number = n;
		title = t;
		author = a;
	}
	int getNumber() 
	{
		return number;
	}
	void setNumber(int n) 
	{
		number = n;
	}
	string getTitle() 
	{
		return title;
	}
	void setTitle(string t) 
	{
		title = t;
	}
	string getAuthor() 
	{
		return author;
	}
	void setAuthor(string a) 
	{
		author = a;
	}
	
 	bool equals(Book b) 
	{
		if( number == b.getNumber() )
			return true;
		else
			return false;
	}
	virtual int getLateFees(int days) = 0;
	void print()
	{
		cout<<"������ȣ : "<<number<<endl;
		cout<<"��    �� : "<<title<<endl;
		cout<<"��    �� : "<<author<<endl;
	}
};

class Novel : public Book 
{
public:
	Novel(int n, string t, string a) : Book(n,t,a) {}
	
	int getLateFees(int days) 
	{
		return days * 300;
	}
};

class Poet : public Book 
{
	
public:
	Poet(int n, string t, string a) : Book(n,t,a) {}
	int getLateFees(int days) 
	{
		return days * 200;
	}
};

class ScienceFiction : public Book 
{
	
public:
	ScienceFiction(int n, string t, string a) : Book(n,t,a) {}
	int getLateFees(int days) 
	{
		return days * 600;
	}
};


int main(void)
{
	Book *b1 = new Novel(1111,"�Ҽ�å","�Ҽ�����");
	Book *b2 = new Poet(1111,"����","����");
	Book *b3 = new ScienceFiction(1111,"�������å","��������");
	
	b1->print();
	cout<<b1->getLateFees(3)<<"��"<<endl;
	b2->print();
	cout<<b2->getLateFees(4)<<"��"<<endl;
	b3->print();
	cout<<b3->getLateFees(5)<<"��"<<endl;
	return 0;
}