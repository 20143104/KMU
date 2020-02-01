#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt_word = 1;
	string text;
	
	cout<<"문자열을 입력하세요 : ";
	getline(cin, text);
	for(int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' '){
			cnt_word++;
		}		
	}

	cout<<"단어의 개수는 : "<<cnt_word<<"개"<<endl;
	return 0;

}
