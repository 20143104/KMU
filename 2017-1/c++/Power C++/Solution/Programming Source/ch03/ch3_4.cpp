#include <iostream>

using namespace std;
int main()
{
	char oper;
	int x, y;
	int result=0;
	cout<<"*************"<<endl;
	cout<<"+---Add"<<endl;
	cout<<"----Subtract"<<endl;
	cout<<"*---Multiply"<<endl;
	cout<<"/---Divide"<<endl;
	cout<<"Q---Quit"<<endl;
	cout<<"*************"<<endl;
	cout<<"�����������Ͻÿ�: ";
	cin>>oper;
	cout<<"�� ���� �������� �и��Ͽ� �Է��Ͻÿ� : ";
	cin>>x>>y;

	switch(oper){
	case '+':
		result = x+y;
		break;
	case '-':
		result = x-y;
		break;
	case '*':
		result = x*y;
		break;
	case '/':
		if( y == 0)
			cout<<"�и� 0�̾ ������ �����ϴ�."<<endl;
		else
			result = x/y;		
		break;
	case 'Q':
		break;
	default:
		cout<<"�߸��Է��ϼ̽��ϴ�."<<endl;
		return 0;
	}
	cout<<result<<endl;

	return 0;
}
