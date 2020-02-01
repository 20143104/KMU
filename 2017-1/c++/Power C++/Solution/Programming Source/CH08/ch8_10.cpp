#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i;
	string str;

	cout<<"문자열을 입력하세요 : ";
	getline(cin, str);

	for(i = str.length() -1; i >= 0; i--)
		cout<<str[i];
	cout<<endl;	

	return 0;
}