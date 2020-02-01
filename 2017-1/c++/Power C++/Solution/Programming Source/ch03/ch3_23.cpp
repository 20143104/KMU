#include <iostream>
using namespace std;

int main()
{
	int num = 0, i;
	cout<<"정수를 입력하세요 : ";
	cin>>num;
	if(num < 0){
		cout<<"오류 메시지) 입력하신 정수는 0보다 작습니다!"<<endl;
		return 0;
	}
	for(i=1; i<= num ; i++){
		if( i % 3 == 0)
			cout<<"["<<i<<"]"<<endl;
	}
	return 0;	
}
