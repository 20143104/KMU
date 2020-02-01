#include <iostream>

using namespace std;

int main(void)
{
	char chr;
	
	cout<< "문자 하나를 입력하세요 : ";
	cin>>chr;
	
	cout<<"아스키코드값을 출력 : " << (int)chr << endl;
	
	return 0;
}
