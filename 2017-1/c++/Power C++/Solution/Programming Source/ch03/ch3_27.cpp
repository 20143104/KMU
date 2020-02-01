#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
	int com[3] = {0}, user[3] = {0}, i;
	char conti;
	
	cout<<"기억력 테스트 게임 입니다."<<endl;
	cout<<"화면에 보이는 숫자들을 기억하였다가 다시 쓰면 됩니다."<<endl;
	
	while(1){
		srand(time(NULL));
		for(i=0; i<=2; i++){
			com[i] = rand() % 9 + 1;
			cout<<com[i] <<"  ";
		}
		Sleep(1000);
		cout<<"\r"<<"                "<<"\r";
		cin>>user[0]>>user[1]>>user[2];

		if( (user[0] == com[0]) && (user[1] == com[1]) && (user[2] == com[2]) )
			cout<<"맞았습니다."<<endl;
		else
			cout<<"틀렸습니다."<<endl;
		cout<<"다시 하시겠습니까?(Y/N) : ";	
		cin>>conti;
		if(conti == 'N' || conti == 'n')
			break;
	}

	return 0;
}
