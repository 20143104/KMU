#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt_vowel = 0, cnt_con = 0;
	string text, search_text, change_text;
	
	cout<<"���ڿ��� �Է��ϼ��� : ";
	getline(cin, text);
	cout<<"ã�� ���ڿ��� �Է��ϼ��� : ";
	cin>>search_text;
	cout<<"�ٲ� ���ڿ��� �Է��ϼ��� : ";
	cin>>change_text;

	text.replace(text.find(search_text),change_text.length(),change_text);

	cout<<text<<endl;
	
	return 0;

}