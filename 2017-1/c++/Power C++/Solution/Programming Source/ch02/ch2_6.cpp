#include <iostream>

using namespace std;

int main()
{
	float weight = 0, pound = 0, ounce = 0;

	cout<<"���Ը� �Է��Ͻÿ�.:";
	cin>>weight;

	pound = weight*2.2;
	ounce = pound*16;

	cout<<weight<<"ų�α׷��� "<<pound<<" �Ŀ���Դϴ�."<<endl;
	cout<<weight<<"ų�α׷��� "<<ounce<<" �½��Դϴ�."<<endl;

	return 0;
}