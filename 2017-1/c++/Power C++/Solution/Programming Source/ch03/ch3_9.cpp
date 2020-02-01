#include <iostream>

using namespace std;

int main()
{
	char c, prt;
	
	cout<<"하나의 문자를 입력하세요 : ";
	cin>>c;
	
	if( !(((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))){
		cout<<"알파벳이 아닙니다.!!"<<endl;
		return 0;
	}
	
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			cout<<"입력하신 문자는 모음입니다.!!^^"<<endl;
			break;
		default:
			cout<<"입력하신 문자는 자음입니다.!!"<<endl;
	}
	return 0;
}
