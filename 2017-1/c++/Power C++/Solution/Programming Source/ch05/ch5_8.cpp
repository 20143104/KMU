#include <iostream>

using namespace std;

int main()
{
	int server[5][1]={ {100},{234},{512},{765},{587} };
	int num;

	cout<<" ������ ��ȣ�� �Է����ּ��� (1~5): ";
	cin>>num;

	while(num>=1){
		if(num <=5)
			cout<<" >>>  "<< server[num-1][0] << "�� �Դϴ�."<<endl;
		else
			cout <<" ��ϵ� ��ȣ�� ������ �ƴմϴ�."<<endl;
		cout<<" ������ ��ȣ�� �Է����ּ��� (1~5): ";
		cin>>num;
	}
	return 0;
}
