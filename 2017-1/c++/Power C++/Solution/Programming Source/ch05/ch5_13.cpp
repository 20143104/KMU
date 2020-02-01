#include <iostream>

using namespace std;

#define MAX_SIZE 5

void array_copy(int a[],int b[], int size);

int main(void)
{
	int a[MAX_SIZE] = {0}, b[MAX_SIZE] = {0};

	cout<<"데이터를 입력하시오(11 42 23 24 33)"<<endl;
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];

	array_copy(a,b,MAX_SIZE);
	cout<<"a[] = { ";
	for(int i = 0;i < MAX_SIZE; i++){
		cout<<a[i]<<" ";
	}
	cout<<"}"<<endl;;
	cout<<"b[] = { ";
	for(i = 0;i < MAX_SIZE; i++){
		cout<<b[i]<<" ";
	}
	cout<<"}"<<endl ;

	return 0;
}
void array_copy(int a[],int b[], int size)
{
	for(int i = 0;i < size; i++){
		b[i] = a[i];
	}
}