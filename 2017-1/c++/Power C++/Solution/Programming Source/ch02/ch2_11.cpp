#include <iostream>


#define PI  3.14159265

using namespace std;

int main()
{
	float radius = 0.0, height = 0.0, volume = 0.0;
	

	cout<<"����� �ظ��� �������� �Է��Ͻÿ�.: ";
	cin>>radius;
	cout<<"������� ���̸� �Է��Ͻÿ�.: ";
	cin>>height;
	
	volume = radius*radius*PI*height;

	cout<<"������� ���Ǵ� "<<volume<<"�Դϴ�."<<endl;
		

	return 0;
}