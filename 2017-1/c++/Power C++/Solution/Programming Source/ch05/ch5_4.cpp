#include <iostream>

using namespace std;

void vector_dot_prod(int v1[], int v2[]);

int main(void)
{
	int vector1[3] = {0}, vector2[3] = {0};

	cout<<"���� x�� �Է��Ͻÿ�(x1 x2 x3) : ";
	cin>>vector1[0]>>vector1[1]>>vector1[2];
	cout<<"���� y�� �Է��Ͻÿ�(y1 y2 y3) : ";
	cin>>vector2[0]>>vector2[1]>>vector2[2];
	vector_dot_prod(vector1,vector2);

	return 0;
}

void vector_dot_prod(int v1[], int v2[])
{
	int vector = 0, i, temp = 0;

	for(i = 0;i < 3; i++){
		temp = v1[i] * v2[i];
		vector += temp;
	}
	cout<<"������ ������ "<<vector<<"�Դϴ�."<<endl;
}