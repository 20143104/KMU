#include <iostream>

using namespace std;

void del_blank(char *,int);

int main(void)
{
	int i=0;
	char str[50];
	
	cout<< "문자열을 입력하세요 : ";
	cin.getline(str, 50);
	
	while(str[i] != NULL)
		i++;
	
	del_blank(str, i);
	cout<<str<<endl;
	
	return 0;
}

void del_blank(char *ch, int n)
{
	int i, j;
	char *p;
	
	p = ch;

	for(i=n; i >=0 ; i--){
		if( p[i] == ' '){
			for(j=i; j <= n ; j++)
				p[j] = p[j+1];	
		}
	}
}