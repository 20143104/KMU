#include <iostream>

using namespace std;

int main()
{
	int hour = 0, min = 0, second = 0, result = 0;
	

	cout<<"�ð��� �Է��Ͻÿ�.(��):";
	cin>>hour;
	cout<<"�ð��� �Է��Ͻÿ�.(��):";
	cin>>min;
	cout<<"�ð��� �Է��Ͻÿ�.(��):";
	cin>>second;
	
	result = hour*3600 + min*60 + second;

	cout<<hour<<"�ð� "<<min<<"�� "<<second<<"�ʴ� "<<result<<" ���Դϴ�."<<endl;
	

	return 0;
}