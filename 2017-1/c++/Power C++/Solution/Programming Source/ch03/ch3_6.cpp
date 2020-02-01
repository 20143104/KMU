#include <iostream>

using namespace std; 

int main()
{
	char c;
	scanf("%c", &c);
	//cin의 경우 공백문자, 개행문자, 탭문자 무시하기 때문에 사용할 수없다.
        
    switch (c)
	{
		case '\t':
			cout<<"탭문자 입니다.\n";
			break;
		case '\n':
			cout<<"줄바꿈문자 입니다.\n";
			break;
		case '\b':
			cout<<"백스페이스 문자 입니다. \n";
            break;
     }
	return 0;
}

