#include <iostream>

using namespace std;

int main()
{
	char sel;
	int width = 0, height = 0, radius = 0;

	cout<<"���ڸ� �Է��ϼ��� (R,T,C) : ";
	cin>>sel;

	switch(sel){

	case 'R':
		cout<<"�غ� ����, ���̸� �Է��ϼ��� :";
		cin>>width>>height;
		cout<<"�簢���� ������ : "<<width*height<<endl;
		break;
	case 'T':
		cout<<"�غ� ����, ���̸� �Է��ϼ��� :";
		cin>>width>>height;
		cout<<"�ﰢ���� ������ : "<<(width*height)/2<<endl;
		break;
	case 'C':
		cout<<"�������� �Է��ϼ��� :";
		cin>>radius;
		cout<<"���� ������ : "<<3.14*(radius*radius)<<endl;
		break;
	
	}

	return 0;
}
