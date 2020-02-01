#include <iostream>
#include <string>

using namespace std;

int main()
{
	string id("HONG");
	string pwd("1234");
	string u_id, u_pwd;

	cout<<" > ID를 입력하세요 : ";
	cin>>u_id;
	cout<<" > 패스워드를 입력하세요 : ";
	cin>>u_pwd;

	if( id == u_id && pwd == u_pwd)
		cout<<" >> ID, 패스워드가 일치합니다. "<<endl;
	else
		cout<<" >> ID, 패스워드가 일치하지 않습니다. "<<endl;

	return 0;
} 