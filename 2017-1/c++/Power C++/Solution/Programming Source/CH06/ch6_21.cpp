#include <iostream>
#define SIZE 81

using namespace std;

int main()
{
	char str[SIZE], tmp[SIZE];
	char findStr[SIZE], replaceStr[SIZE];
	
	char* pStr;
	
	cout<<"���ڿ��� �Է��Ͻÿ�: ";
	cin.getline(str, 81);

	cout<<"ã�� ���ڿ�: ";
	cin.getline(findStr,81);

	cout<<"�ٲ� ���ڿ�: ";
	cin.getline(replaceStr,81);
	pStr = strstr(str, findStr);

	if(findStr == NULL)
		cout<<"�Է��Ͻ� ���ڿ��� ã�� �� �����ϴ�."<<endl;

	strncpy(tmp, str, (pStr-str));
	tmp[pStr-str] = NULL;
	strcat(tmp, replaceStr);
	strcat(tmp, pStr+strlen(findStr));

	strcpy(str, tmp);

	cout<<"���: "<<str<<endl;
	
	return 0;
}