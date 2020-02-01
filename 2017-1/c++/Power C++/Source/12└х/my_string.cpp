#include <iostream>
using namespace std;

class MyString
{
private:
	char *pBuf; 		//�������� �Ҵ�� �޸��� �ּҰ� ����

public:
	MyString(const char *s=NULL); 
	MyString(MyString& s);
	~MyString();

	void print();    	// ���ڿ��� ȭ�鿡 ���
	int getSize();   	// ���ڿ��� ���� ��ȯ
	MyString operator+(MyString& s);	// + ������ �ߺ� ����
};

// ������
MyString::MyString(const char *s)
{
	if( s == NULL )
	{
		pBuf = new char[1];
		pBuf[0] = NULL;
	}
	else 
	{
		pBuf = new char[::strlen(s)+1];
		strcpy(pBuf, s);
	}
}

// ���� ������
MyString::MyString(MyString &s)
{
	pBuf = new char[s.getSize()+1];
	strcpy(pBuf, s.pBuf);
}

// �Ҹ���
MyString::~MyString()
{
	if ( pBuf )
		delete [] pBuf;
}

void MyString::print()
{
	cout << pBuf << endl;
}

int MyString::getSize()
{
	return strlen(pBuf);
}
MyString MyString::operator+(MyString& s)
{
	char *temp = new char[getSize() + s.getSize() + 1];
	strcpy(temp, pBuf);
	strcat(temp, s.pBuf);
	MyString r(temp);
	delete [] temp;
	return r;
}

int main() {

	MyString s1("Hello ");
	MyString s2("World!");
	MyString s3 = s1 + s2;

	s1.print();
	s2.print();
	s3.print();

	return 0;
}
