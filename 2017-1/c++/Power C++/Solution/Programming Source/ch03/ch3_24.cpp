#include <iostream>

using namespace std;

int main()
{
	int answer = 27;
	int num;

	cout<<"1���� 100������ ���� ���纸���� ";
	cin>>num;

	while(num != answer){
		if(answer > num)
			cout<<">> �Է��Ͻ� ���ں��� �����ϴ�."<<endl;
		else if(answer < num)
			cout<<">> �Է��Ͻ� ���ں��� �����ϴ�."<<endl;

		cout<<"1���� 100������ ���� ���纸���� ";
		cin>>num;

	}
	cout<<"-----> �����Դϴ�!!"<<endl;

	return 0;
}
