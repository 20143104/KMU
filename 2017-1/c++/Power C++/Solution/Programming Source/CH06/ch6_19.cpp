#include <iostream>

int get_response(char *prompt);

using namespace std;

int main()
{
	char question[] = "Are you a student?";
	
	cout<<"���� : "<<question<<endl;
	
	if(get_response(question) == 1)
		cout<<"�������� �亯�Դϴ�."<<endl;
	else
		cout<<"�������� �亯�Դϴ�."<<endl;
	
	return 0;
}

int get_response(char *prompt)
{
	char answer[50];
	
	cout << "���: ";
	cin >> answer;

	strlwr(answer);
	
	if((strcmp(answer,"yes")) == 0 || (strcmp(answer,"ok")) == 0){
		return 1;
	}
	else if( strcmp(answer,"no") == 0 ){
		return 0;
	}
	return 0;
}
