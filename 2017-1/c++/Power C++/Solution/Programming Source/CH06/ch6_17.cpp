#include <iostream>

using namespace std;

int main()
{
	char str[100], *pStr[4];
	int i, cnt = 0;
	
	cout<<"이름을 입력하세요(성 이름)(ex : HONG GIL DONG) : ";
	cin.getline(str, 200);
	
	if((pStr[cnt++] = strtok(str, " ")) )
		while( (pStr[cnt++] = strtok(NULL, " ")) );
	
	if(cnt == 3)
		cout<<*pStr[1]<<". "<<pStr[0]<<endl;
	else if(cnt == 4)
		cout<<*pStr[1]<<". "<<*pStr[2]<<". "<<pStr[0]<<endl;
	else if(cnt == 5)
		cout<<*pStr[1]<<". "<<*pStr[2]<<". "<<*pStr[3]<<". "<<pStr[0]<<endl;

	return 0;
}