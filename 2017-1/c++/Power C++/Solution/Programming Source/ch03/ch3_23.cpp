#include <iostream>
using namespace std;

int main()
{
	int num = 0, i;
	cout<<"������ �Է��ϼ��� : ";
	cin>>num;
	if(num < 0){
		cout<<"���� �޽���) �Է��Ͻ� ������ 0���� �۽��ϴ�!"<<endl;
		return 0;
	}
	for(i=1; i<= num ; i++){
		if( i % 3 == 0)
			cout<<"["<<i<<"]"<<endl;
	}
	return 0;	
}
