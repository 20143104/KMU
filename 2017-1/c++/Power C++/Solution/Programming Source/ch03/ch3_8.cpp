#include <iostream>

using namespace std;

int main()
{
	char c, prt;

	cout<<"하나의 문자를 입력하세요 : ";
	cin>>c;

	if( (c >= 'A') && (c <= 'Z')){
		prt = c-'A'+'a';
		cout<<prt<<endl;
	}
	else if( (c >= 'a') && (c <='z'))
		cout<<"대문자를 입력하세요 !"<<endl;
}
