#include <iostream>

using namespace std;

int main()
{
	int answer = 27;
	int num;

	cout<<"1부터 100사이의 수를 맞춰보세요 ";
	cin>>num;

	while(num != answer){
		if(answer > num)
			cout<<">> 입력하신 숫자보다 높습니다."<<endl;
		else if(answer < num)
			cout<<">> 입력하신 숫자보다 낮습니다."<<endl;

		cout<<"1부터 100사이의 수를 맞춰보세요 ";
		cin>>num;

	}
	cout<<"-----> 정답입니다!!"<<endl;

	return 0;
}
