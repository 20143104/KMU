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
	
	cout<<" scissor,rock,paper �� �����ϼ��� : ";
	cin>>user;
	
	com1_choice = rand()%2;

	if( user == "scissor"){
		if(com1[com1_choice] == "rock")
			cout<<"��ǻ�ʹ� rock�� ���� ��ǻ�Ͱ� �̰���ϴ�.!!"<<endl;
		else if(com1[com1_choice] == "paper")
			cout<<"��ǻ�ʹ� paper�� ���� ����ڰ� �̰���ϴ�.!!"<<endl;
		else if(com1[com1_choice] == "scissor")
			cout<<"��ǻ�ʹ� scissor�� ���� �����ϴ�.!!"<<endl;
	}
	else if(user == "rock"){
		if(com1[com1_choice] == "rock")
			cout<<"��ǻ�ʹ� rock�� ���� �����ϴ�.!!"<<endl;
		else if(com1[com1_choice] == "paper")
			cout<<"��ǻ�ʹ� paper�� ���� ��ǻ�Ͱ� �̰���ϴ�.!!"<<endl;
		else if(com1[com1_choice] == "scissor")
			cout<<"��ǻ�ʹ� scissor�� ���� ����ڰ� �̰���ϴ�.!!"<<endl;
	}
	else if(user == "paper"){
		if(com1[com1_choice] == "rock")
			cout<<"��ǻ�ʹ� rock�� ���� ����ڰ� �̰���ϴ�.!!"<<endl;
		else if(com1[com1_choice] == "paper")
			cout<<"��ǻ�ʹ� paper�� ���� �����ϴ�.!!"<<endl;
		else if(com1[com1_choice] == "scissor")
			cout<<"��ǻ�ʹ� scissor�� ���� ��ǻ�Ͱ� �̰���ϴ�.!!"<<endl;
	}

	return 0;
}
