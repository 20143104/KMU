#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt_vowel = 0, cnt_con = 0;
	string text, search_text, change_text;
	
	cout<<"문자열을 입력하세요 : ";
	getline(cin, text);
	cout<<"찾을 문자열을 입력하세요 : ";
	cin>>search_text;
	cout<<"바꿀 문자열을 입력하세요 : ";
	cin>>change_text;

	text.replace(text.find(search_text),change_text.length(),change_text);

	cout<<text<<endl;
	
	return 0;

}