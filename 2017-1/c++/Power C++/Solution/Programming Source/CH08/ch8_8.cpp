#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt_al = 0, cnt_bl = 0, cnt_num = 0;
	string text;
	
	cout<<"문자열을 입력하세요 : ";
	getline(cin, text);

	for(int i=0; i < text.length(); i++)
	{
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
			cnt_al++;
		else if(text[i] >= '1' && text[i] <= '9')
			cnt_num++;
		else if(text[i] == ' ')
			cnt_bl++;
	}

	cout<<"알파벳 글자의 갯수는 : "<<cnt_al<<"개"<<endl;
	cout<<"숫자의 갯수는 : "<<cnt_num<<"개"<<endl;
	cout<<"공백 문자의 갯수는 : "<<cnt_bl<<"개"<<endl;

	return 0;

}