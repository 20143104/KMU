#include <iostream>

using namespace std;

int str_len(char *s);

int main()
{

	char *str = "I love you";
	cout<<"���ڿ��� ��� �ִ� ���ڵ��� ������ : "<<str_len(str)<<endl;
}


int str_len(char *s)
{
	int i=0;

	while( *(s+i) != NULL)
		i++;
	return i;
}
