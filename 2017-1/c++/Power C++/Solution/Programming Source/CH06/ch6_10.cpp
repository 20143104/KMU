#include <iostream>
#define MAX_SIZE 10

using namespace std;

void merge(int *A, int *B, int *C);

int main ()
{
	int a[MAX_SIZE/2] = {1,3,4,7,8};
	int b[MAX_SIZE/2] = {2,5,6,9,10};
	int c[MAX_SIZE] = {0};

	cout<<"A[] = { ";
	for(int i = 0;i < MAX_SIZE/2;i++){
		cout<<a[i]<<" ";
	}
	cout<<"}"<<endl;

	cout<<"B[] = { ";
	for(i = 0;i < MAX_SIZE/2;i++){
		cout<<b[i]<<" ";
	}
	cout<<"}"<<endl;
	merge(a,b,c);

	cout<<"C[] = { ";
	for(i = 0;i < MAX_SIZE;i++){
		cout<<c[i]<<" ";
	}
	cout<<"}"<<endl;
	return 0;
}
void merge(int *A, int *B, int *C)
{
	int i = 0, j = 0, k = 0;

	while(k != MAX_SIZE){
		if(A[i] <= B[j]){
			C[k] = A[i];
			i++;
		}
		else{
			C[k] = B[j];
			j++;
		}
		k++;
	}
}