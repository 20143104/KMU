#include <iostream>

using namespace std;

int main()
{
	int test1 = 0, test2 = 0, quiz = 0, score = 0;
	cout<<"�߰���� ������ �Է��ϼ��� : ";
	cin>>test1;

	cout<<"�⸻��� ������ �Է��ϼ��� : ";
	cin>>test2;

	cout<<"���� ������ �Է��ϼ��� : ";
	cin>>quiz;

	score = (0.4*test1)+(0.5*test2)+(0.1*quiz);

	if( score >= 90 )
		cout<<"[ A���� �Դϴ�. ]"<<endl;
	else if( score >=80 )
		cout<<"[ B���� �Դϴ�. ]"<<endl;
	else if( score >=70 )
		cout<<"[ C���� �Դϴ�. ]"<<endl;
	else if( score >=60 )
		cout<<"[ D���� �Դϴ�. ]"<<endl;
	else if( score < 60)
		cout<<"[ F���� �Դϴ�. ]"<<endl;

	return 0;
}
