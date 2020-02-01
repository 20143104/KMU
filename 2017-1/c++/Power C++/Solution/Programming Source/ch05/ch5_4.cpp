#include <iostream>

using namespace std;

void vector_dot_prod(int v1[], int v2[]);

int main(void)
{
	int vector1[3] = {0}, vector2[3] = {0};

	cout<<"벡터 x를 입력하시오(x1 x2 x3) : ";
	cin>>vector1[0]>>vector1[1]>>vector1[2];
	cout<<"벡터 y를 입력하시오(y1 y2 y3) : ";
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
	cout<<"벡터의 내적은 "<<vector<<"입니다."<<endl;
}