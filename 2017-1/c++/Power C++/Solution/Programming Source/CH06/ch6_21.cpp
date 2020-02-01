#include <iostream>
#define SIZE 81

using namespace std;

int main()
{
	char str[SIZE], tmp[SIZE];
	char findStr[SIZE], replaceStr[SIZE];
	
	char* pStr;
	
	cout<<"문자열을 입력하시오: ";
	cin.getline(str, 81);

	cout<<"찾을 문자열: ";
	cin.getline(findStr,81);

	cout<<"바꿀 문자열: ";
	cin.getline(replaceStr,81);
	pStr = strstr(str, findStr);

	if(findStr == NULL)
		cout<<"입력하신 문자열을 찾을 수 없습니다."<<endl;

	strncpy(tmp, str, (pStr-str));
	tmp[pStr-str] = NULL;
	strcat(tmp, replaceStr);
	strcat(tmp, pStr+strlen(findStr));

	strcpy(str, tmp);

	cout<<"결과: "<<str<<endl;
	
	return 0;
}