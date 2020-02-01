#include <iostream>

using namespace std;

int main()
{
	char str[200], *pStr[50];
	int i, cnt = 0;

	cout<<"문자열 입력 : ";
	cin.getline(str, 200);

	if((pStr[cnt++] = strtok(str, " ")) )
		while( (pStr[cnt++] = strtok(NULL, " ")) );


	for(i=cnt-2; i>=0; i--)
		cout<<pStr[i]<<" ";
		
	cout<<endl;
	return 0;
}
