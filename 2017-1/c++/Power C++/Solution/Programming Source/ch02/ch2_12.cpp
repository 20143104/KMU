#include <iostream>

using namespace std;

int main()
{
	float distance = 0, min = 0, second = 0, speed = 0;

	

	cout<<"�޸� �Ÿ��� �Է��Ͻÿ�(km).: ";
	cin>>distance;
	cout<<"�޸� �ð� �߿��� ���� �Է��Ͻÿ�.: ";
	cin>>min;
	cout<<"�޸� �ð� �߿��� �ʸ� �Է��Ͻÿ�.: ";
	cin>>second;
	
	speed = distance/((min+(second/60))/60);
	

	cout<<"��� �ӵ��� "<<speed<<" km/h�Դϴ�."<<endl;
		

	return 0;
}