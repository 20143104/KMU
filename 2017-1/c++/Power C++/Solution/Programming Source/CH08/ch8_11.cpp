#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt_vowel = 0, cnt_con = 0;
	string text;
	
	cout<<"문자열을 입력하세요 : ";
	getline(cin, text);

	for(int i=0; i < text.length(); i++)
	{
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')){
			if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ){
				cnt_vowel++;
			}
			else{
				cnt_con++;
			}
		}
	}

	cout<<"자음의 개수는 : "<<cnt_vowel<<"개"<<endl;
	cout<<"모음의 개수는 : "<<cnt_con<<"개"<<endl;
	return 0;

}