#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cout << "�ֹε�Ϲ�ȣ�� �Է��Ͻÿ�: ";
	cin >> s;

	cout << "-�� ���ŵ� �ֹε�Ϲ�ȣ: ";
	for(int i=0;i < s.length();i++){
		if( s[i] == '-' ) continue;
		cout << s[i];
	}
	cout << endl;

	return 0;
}	
