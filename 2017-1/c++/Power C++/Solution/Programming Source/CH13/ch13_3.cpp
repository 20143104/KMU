#include <iostream>
#include <string>

using namespace std;

class Book{
private:
	string bname;
	int page;
	string author;
public:
	Book(string bn, int p, string a)
	{
		bname = bn;
		page = p;
		author = a;
	}
	void setBname(string bn)
	{
		bname = bn;
	}
	void setPage(int p)
	{
		page = p;
	}
	void setAuthor(string a)
	{
		author = a;
	}
	string getBname()
	{
		return bname;
	}
	int getPage()
	{
		return page;
	}
	string getAuthor()
	{
		return author;
	}
};

class Magazine : public Book{
private:
	string date;
public:
	Magazine(string bn, int p, string a, string d) : Book(bn, p, a)
	{
		date = d;
	}
	void setDate(string d)
	{
		date = d;
	}
	string getDate()
	{
		return date;
	}
	
};

int main()
{
	
	return 0;	
}