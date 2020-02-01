#include <iostream>

using namespace std;

int main()
{
	int test1 = 0, test2 = 0, quiz = 0, score = 0;
	cout<<"중간고사 점수를 입력하세요 : ";
	cin>>test1;

	cout<<"기말고사 점수를 입력하세요 : ";
	cin>>test2;

	cout<<"퀴즈 점수를 입력하세요 : ";
	cin>>quiz;

	score = (0.4*test1)+(0.5*test2)+(0.1*quiz);

	if( score >= 90 )
		cout<<"[ A학점 입니다. ]"<<endl;
	else if( score >=80 )
		cout<<"[ B학점 입니다. ]"<<endl;
	else if( score >=70 )
		cout<<"[ C학점 입니다. ]"<<endl;
	else if( score >=60 )
		cout<<"[ D학점 입니다. ]"<<endl;
	else if( score < 60)
		cout<<"[ F학점 입니다. ]"<<endl;

	return 0;
}
