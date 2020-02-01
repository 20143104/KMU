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
	cout<<"연산을선택하시요: ";
	cin>>oper;
	cout<<"두 수를 공백으로 분리하여 입력하시요 : ";
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
			cout<<"분모가 0이어서 나눌수 없습니다."<<endl;
		else
			result = x/y;		
		break;
	case 'Q':
		break;
	default:
		cout<<"잘못입력하셨습니다."<<endl;
		return 0;
	}
	cout<<result<<endl;

	return 0;
}
