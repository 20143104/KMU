#include <iostream>

using namespace std;

int main()
{
	char c, prt;

	cout<<"�ϳ��� ���ڸ� �Է��ϼ��� : ";
	cin>>c;

	if( (c >= 'A') && (c <= 'Z')){
		prt = c-'A'+'a';
		cout<<prt<<endl;
	}
	else if( (c >= 'a') && (c <='z'))
		cout<<"�빮�ڸ� �Է��ϼ��� !"<<endl;
}
