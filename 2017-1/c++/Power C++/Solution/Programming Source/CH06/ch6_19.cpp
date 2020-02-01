#include <iostream>

int get_response(char *prompt);

using namespace std;

int main()
{
	char question[] = "Are you a student?";
	
	cout<<"질문 : "<<question<<endl;
	
	if(get_response(question) == 1)
		cout<<"긍정적인 답변입니다."<<endl;
	else
		cout<<"부정적인 답변입니다."<<endl;
	
	return 0;
}

int get_response(char *prompt)
{
	char answer[50];
	
	cout << "대답: ";
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
