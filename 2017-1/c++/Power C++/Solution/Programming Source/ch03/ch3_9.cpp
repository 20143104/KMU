#include <iostream>

using namespace std;

int main()
{
	char c, prt;
	
	cout<<"�ϳ��� ���ڸ� �Է��ϼ��� : ";
	cin>>c;
	
	if( !(((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))){
		cout<<"���ĺ��� �ƴմϴ�.!!"<<endl;
		return 0;
	}
	
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			cout<<"�Է��Ͻ� ���ڴ� �����Դϴ�.!!^^"<<endl;
			break;
		default:
			cout<<"�Է��Ͻ� ���ڴ� �����Դϴ�.!!"<<endl;
	}
	return 0;
}
