#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt_word = 1;
	string text;
	
	cout<<"���ڿ��� �Է��ϼ��� : ";
	getline(cin, text);
	for(int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' '){
			cnt_word++;
		}		
	}

	cout<<"�ܾ��� ������ : "<<cnt_word<<"��"<<endl;
	return 0;

}
