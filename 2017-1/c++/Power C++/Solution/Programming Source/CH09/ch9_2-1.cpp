#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
	string title;
	string author;
};

int main()
{
	Book book1;

	book1.title = "Creat C++";
	book1.author = "bob";

	cout<<book1.title<<" - "<<book1.author<<endl;

	return 0;
}