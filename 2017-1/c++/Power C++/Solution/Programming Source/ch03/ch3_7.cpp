#include <iostream>

using namespace std;

int main()
{
	int count = 0, sum = 0;
	cout<<"������ ������ �Է����ּ��� :";
	cin>>count;

	if(count >= 10){
		sum = count * 100 * 0.9;
	}
	else{
		sum = count * 100;
	}
	cout<<"������ ��ü ������ : "<<sum<<"���Դϴ�."<<endl;
	return 0;
}
