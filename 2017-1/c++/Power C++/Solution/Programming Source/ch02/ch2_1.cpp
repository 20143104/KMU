#include <iostream>

using namespace std;

int main()
{
	short height = 0, lenth = 0, width = 0;
	int cubage = 0;

	cout<<"������ ���̸� �Է��Ͻÿ�:";
	cin>>height;
	cout<<"������ ���̸� �Է��Ͻÿ�:";
	cin>>lenth;
	cout<<"������ �ʺ� �Է��Ͻÿ�:";
	cin>>width;

	cubage = height*lenth*width;

	cout<<"������ ü���� "<<cubage<<"�Դϴ�."<<endl;

	return 0;
}