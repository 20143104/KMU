#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt_al = 0, cnt_bl = 0, cnt_num = 0;
	string text;
	
	cout<<"���ڿ��� �Է��ϼ��� : ";
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

	cout<<"���ĺ� ������ ������ : "<<cnt_al<<"��"<<endl;
	cout<<"������ ������ : "<<cnt_num<<"��"<<endl;
	cout<<"���� ������ ������ : "<<cnt_bl<<"��"<<endl;

	return 0;

}