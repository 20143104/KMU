#include <iostream>
#define MAX_SIZE 10

using namespace std;
void print(int *A, int size);
int *search(int *A, int n);

int main ()
{
	int a[MAX_SIZE] = {1,2,3,4,5,6,7,8,9,10}, n =0, *ps = NULL;
	print(a,MAX_SIZE);

	cout<<"Ž���� ���� �Է��Ͻÿ� : ";
	cin>>n;
	
	ps = search(a,n);
	
	if(*ps == -1){
		cout<<"��ã�ҽ��ϴ�."<<endl;
	}
	else{
		cout<<"ã�ҽ��ϴ� : "<<*ps<<endl;
	}

	return 0;
}

int *search(int *A, int n)
{
	int x = -1;
	for(int i = 0;i < MAX_SIZE;i++){
		if(*A+i == n){
			return A+i;
		}
	}

	return &x;
}
void print(int *A,int size)
{
	cout<<"A[] = { ";
	for(int i = 0;i < size;i++){
		cout<<A[i]<<" ";
	}
	cout<<"}"<<endl;
}