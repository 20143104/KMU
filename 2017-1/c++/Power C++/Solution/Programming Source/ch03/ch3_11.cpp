#include <iostream>

using namespace std;

int main()
{
	int height=0, ave_weight=0, weight = 0;
	cout<<"Ű�� �Է����ּ��� : ";
	cin>>height;

	ave_weight = (height - 100) * 0.9;
	cout<<"�����Ը� �Է����ּ��� : ";
	cin>>weight;

	if(weight > ave_weight)
		cout<<"�˸�)��ü���Դϴ�."<<endl;
	else if(weight == ave_weight)
		cout<<"�˸�)ǥ�� ü���Դϴ�."<<endl;
	else
		cout<<"�˸�)��ü���Դϴ�."<<endl;
	return 0;
}
