#include <iostream>
#define SIZE 100
using namespace std;

int isalpha(char *);

int main()
{
	char str[SIZE];

	cout<<"영문 문자열을 입력하세요 : ";
	cin.getline(str, SIZE); // cin은 공백문자를 무시하기 때문에 getline()을 사용
	cout<<"영단어의 개수는 : "<<isalpha(str)<<endl;

	
}

int isalpha(char *st)
{
	int i;
	int cnt = 1;

	for(i=0; i< SIZE; i++){
		if(st[i] == NULL)
			break;
		else if(st[i] == ' ')
			cnt++;
	}
	return cnt;

}
