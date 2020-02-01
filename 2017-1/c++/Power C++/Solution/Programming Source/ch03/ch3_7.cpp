#include <iostream>

using namespace std;

int main()
{
	int count = 0, sum = 0;
	cout<<"물건의 개수를 입력해주세요 :";
	cin>>count;

	if(count >= 10){
		sum = count * 100 * 0.9;
	}
	else{
		sum = count * 100;
	}
	cout<<"물건의 전체 가격은 : "<<sum<<"원입니다."<<endl;
	return 0;
}
