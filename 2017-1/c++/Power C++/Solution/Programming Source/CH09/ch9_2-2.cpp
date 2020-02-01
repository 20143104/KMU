#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
	string title;
	string author;
public:
	void setTitle(string m_title)
	{
		title = m_title;
	}
	void setAuthor(string m_author)
	{
		author = m_author;
	}
	string getTitle()
	{
		return title;
	}
	string getAuthor()
	{
		return author;	
	}
};

int main()
{
	Book book1;

	book1.setTitle("Creat C++");
	book1.setAuthor("bob");

	cout<<book1.getTitle()<<" - "<<book1.getAuthor()<<endl;

	return 0;
}