#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	int com1_choice;
	string user;
	
	string com1[3]={"scissor","rock","paper"};
	srand((unsigned)time(NULL));
	
	cout<<" scissor,rock,paper 를 선택하세요 : ";
	cin>>user;
	
	com1_choice = rand()%2;

	if( user == "scissor"){
		if(com1[com1_choice] == "rock")
			cout<<"컴퓨터는 rock를 내서 컴퓨터가 이겼습니다.!!"<<endl;
		else if(com1[com1_choice] == "paper")
			cout<<"컴퓨터는 paper를 내서 사용자가 이겼습니다.!!"<<endl;
		else if(com1[com1_choice] == "scissor")
			cout<<"컴퓨터는 scissor를 내서 비겼습니다.!!"<<endl;
	}
	else if(user == "rock"){
		if(com1[com1_choice] == "rock")
			cout<<"컴퓨터는 rock를 내서 비겼습니다.!!"<<endl;
		else if(com1[com1_choice] == "paper")
			cout<<"컴퓨터는 paper를 내서 컴퓨터가 이겼습니다.!!"<<endl;
		else if(com1[com1_choice] == "scissor")
			cout<<"컴퓨터는 scissor를 내서 사용자가 이겼습니다.!!"<<endl;
	}
	else if(user == "paper"){
		if(com1[com1_choice] == "rock")
			cout<<"컴퓨터는 rock를 내서 사용자가 이겼습니다.!!"<<endl;
		else if(com1[com1_choice] == "paper")
			cout<<"컴퓨터는 paper를 내서 비겼습니다.!!"<<endl;
		else if(com1[com1_choice] == "scissor")
			cout<<"컴퓨터는 scissor를 내서 컴퓨터가 이겼습니다.!!"<<endl;
	}

	return 0;
}
