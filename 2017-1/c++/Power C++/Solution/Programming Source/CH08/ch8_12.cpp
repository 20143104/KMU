#include <iostream>
#include <string>

using namespace std;

int main()
{
	string id("HONG");
	string pwd("1234");
	string u_id, u_pwd;

	cout<<" > ID�� �Է��ϼ��� : ";
	cin>>u_id;
	cout<<" > �н����带 �Է��ϼ��� : ";
	cin>>u_pwd;

	if( id == u_id && pwd == u_pwd)
		cout<<" >> ID, �н����尡 ��ġ�մϴ�. "<<endl;
	else
		cout<<" >> ID, �н����尡 ��ġ���� �ʽ��ϴ�. "<<endl;

	return 0;
} 