#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
	int com[3] = {0}, user[3] = {0}, i;
	char conti;
	
	cout<<"���� �׽�Ʈ ���� �Դϴ�."<<endl;
	cout<<"ȭ�鿡 ���̴� ���ڵ��� ����Ͽ��ٰ� �ٽ� ���� �˴ϴ�."<<endl;
	
	while(1){
		srand(time(NULL));
		for(i=0; i<=2; i++){
			com[i] = rand() % 9 + 1;
			cout<<com[i] <<"  ";
		}
		Sleep(1000);
		cout<<"\r"<<"                "<<"\r";
		cin>>user[0]>>user[1]>>user[2];

		if( (user[0] == com[0]) && (user[1] == com[1]) && (user[2] == com[2]) )
			cout<<"�¾ҽ��ϴ�."<<endl;
		else
			cout<<"Ʋ�Ƚ��ϴ�."<<endl;
		cout<<"�ٽ� �Ͻðڽ��ϱ�?(Y/N) : ";	
		cin>>conti;
		if(conti == 'N' || conti == 'n')
			break;
	}

	return 0;
}
