#include <iostream>

using namespace std;

int main()
{
	float saving = 0, rate = 0, result = 0, temp = 0;

	

	cout<<"���ݾ��� �Է��Ͻÿ�: ";
	cin>>saving;
	cout<<"�������� �Է��Ͻÿ�(���� �ۼ�Ʈ): ";
	cin>>rate;
	temp = saving + (saving * (rate/100));
	result = temp + (temp * (rate/100));

	cout<<"2�� ���� ���ݾ��� "<<result<<"�Դϴ�."<<endl;
		

	return 0;
}