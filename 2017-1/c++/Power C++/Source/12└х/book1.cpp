#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
	int isbn;	// å�� ISBN
	string title;	// å�� ����
public:
	Book() { // ������
		isbn = 0;
		title = ��unknown";
	}
	Book(int isbn) {		
		this->isbn = isbn;
		this->title = "unknown";

	}
	void display() {
		cout << isbn << ":" << title << endl;
	}
};

int main()
{
	Book b1 = 9782001;	// int Ÿ���� Book Ÿ�Կ� ����
	b1.display();
	b1 = 9783001;	// ����
	b1.display();
	return 0;
}
