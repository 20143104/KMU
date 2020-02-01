#include <iostream>
using namespace std;

class String
{
private:
	char *pBuf; 	
public:
	String(const char *s=NULL); 
	String(String& s);
	~String();
	
	void print();
	int getSize();
	String operator+(String& s);
	bool operator!();
	bool String::operator==(String p);
	bool String::operator!=(String p);
	bool String::operator<(String p);
	bool String::operator>(String p);
	bool String::operator<=(String p);
	bool String::operator>=(String p);
};

String::String(const char *s)
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

String::String(String &s)
{
	pBuf = new char[s.getSize()+1];
	strcpy(pBuf, s.pBuf);
}

String::~String()
{
	if ( pBuf )
		delete [] pBuf;
}

void String::print()
{
	cout << pBuf << endl;
}

int String::getSize()
{
	return strlen(pBuf);
}

String String::operator+(String& s)
{
	char *temp = new char[getSize() + s.getSize() + 1];
	strcpy(temp, pBuf);
	strcat(temp, s.pBuf);
	String r(temp);
	delete [] temp;
	return r;
}

bool String::operator!()
{
	if(this->pBuf == NULL || this->pBuf[0] == NULL)
		return true;
	return false;
}


bool String::operator==(String p)
{
	if(strcmp(this->pBuf, p.pBuf) == 0)
		return true;
	return false;
}

bool String::operator!=(String p)
{
	if(strcmp(this->pBuf, p.pBuf) != 0)
		return true;
	return false;
}

bool String::operator<(String p)
{
	if(strcmp(this->pBuf, p.pBuf) < 0)
		return true;
	return false;
}

bool String::operator>(String p)
{
	if(strcmp(this->pBuf, p.pBuf) > 0)
		return true;
	return false;
}

bool String::operator<=(String p)
{
	if(strcmp(this->pBuf, p.pBuf) <= 0)
		return true;
	return false;
}

bool String::operator>=(String p)
{
	if(strcmp(this->pBuf, p.pBuf) >= 0)
		return true;
	return false;
}

int main() {
	
	String s1("Hello ");
	String s2("World!");
	String s3 = s1 + s2;
	String s4;
	String s5("Hello ");
	s1.print();
	s2.print();
	s3.print();

	cout<<"String s4 : ";
	cout<<(!s4)<<endl;

	cout<<"s1(Hello) == s5(Hello) : ";
	cout<<(s1==s5)<<endl;
	cout<<"s1(Hello) != s5(Hello) : ";
	cout<<(s1!=s5)<<endl;
	cout<<"s1(Hello) < s2(World!) : ";
	cout<<(s1<s2)<<endl;
	cout<<"s1(Hello) > s2(World!) : ";
	cout<<(s1>s2)<<endl;
	cout<<"s1(Hello) <= s2(World!) : ";
	cout<<(s1<=s2)<<endl;
	cout<<"s1(Hello) >= s2(World!) : ";
	cout<<(s1>=s2)<<endl;
	return 0;
}
