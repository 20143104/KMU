#include <iostream>

using namespace std;

int main(void)
{
	int product[11] = {0,1,2,3,4,5,1,2,3,4,5}, num = 0;

	cout<<"물품의 번호를 입력하시오 : ";
	cin>>num;

	cout<<"물품의 위치는 "<<product[num]<<"에 있습니다."<<endl;

	return 0;
}
