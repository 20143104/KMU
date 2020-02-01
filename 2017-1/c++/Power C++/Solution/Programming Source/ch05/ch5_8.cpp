#include <iostream>

using namespace std;

int main()
{
	int server[5][1]={ {100},{234},{512},{765},{587} };
	int num;

	cout<<" 서버의 번호를 입력해주세요 (1~5): ";
	cin>>num;

	while(num>=1){
		if(num <=5)
			cout<<" >>>  "<< server[num-1][0] << "명 입니다."<<endl;
		else
			cout <<" 등록된 번호의 서버가 아닙니다."<<endl;
		cout<<" 서버의 번호를 입력해주세요 (1~5): ";
		cin>>num;
	}
	return 0;
}
