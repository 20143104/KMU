#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt_vowel = 0, cnt_con = 0;
	string text;
	
	cout<<"���ڿ��� �Է��ϼ��� : ";
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

	cout<<"������ ������ : "<<cnt_vowel<<"��"<<endl;
	cout<<"������ ������ : "<<cnt_con<<"��"<<endl;
	return 0;

}