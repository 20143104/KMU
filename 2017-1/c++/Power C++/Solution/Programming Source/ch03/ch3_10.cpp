#include <iostream>

using namespace std;

int main()
{
	int input;
	cout<<"�Ｎ�������α׷� (1���� 10������ ��ȣ�� �Է��ϼ���) : ";
	cin>>input;

	if( input == 2)
		cout<<"���ϵ帳�ϴ�!! 1� ��÷�Ǽ̽��ϴ�..!!^^;"<<endl;
	else if( input == 5)
		cout<<"���ϵ帳�ϴ�!! 2� ��÷�Ǽ̽��ϴ�..!!^^;"<<endl;
	else if( input == 3)
		cout<<"���ϵ帳�ϴ�!! 3� ��÷�Ǽ̽��ϴ�..!!^^;"<<endl;
	else
		cout<<"������ȸ�� �븮����!!^^"<<endl;
	return 0;
}
