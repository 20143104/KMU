#include <iostream>

using namespace std;

int main()
{
	int input;
	cout<<"즉석복권프로그램 (1부터 10사이의 번호를 입력하세요) : ";
	cin>>input;

	if( input == 2)
		cout<<"축하드립니다!! 1등에 당첨되셨습니다..!!^^;"<<endl;
	else if( input == 5)
		cout<<"축하드립니다!! 2등에 당첨되셨습니다..!!^^;"<<endl;
	else if( input == 3)
		cout<<"축하드립니다!! 3등에 당첨되셨습니다..!!^^;"<<endl;
	else
		cout<<"다음기회를 노리세요!!^^"<<endl;
	return 0;
}
