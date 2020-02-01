#include <iostream>

using namespace std;

int main()
{
	int height=0, ave_weight=0, weight = 0;
	cout<<"키를 입력해주세요 : ";
	cin>>height;

	ave_weight = (height - 100) * 0.9;
	cout<<"몸무게를 입력해주세요 : ";
	cin>>weight;

	if(weight > ave_weight)
		cout<<"알림)과체중입니다."<<endl;
	else if(weight == ave_weight)
		cout<<"알림)표준 체중입니다."<<endl;
	else
		cout<<"알림)저체중입니다."<<endl;
	return 0;
}
