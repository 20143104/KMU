#include <iostream>

using namespace std;

int str_len(char *s);

int main()
{

	char *str = "I love you";
	cout<<"문자열에 들어 있는 문자들의 개수는 : "<<str_len(str)<<endl;
}


int str_len(char *s)
{
	int i=0;

	while( *(s+i) != NULL)
		i++;
	return i;
}
