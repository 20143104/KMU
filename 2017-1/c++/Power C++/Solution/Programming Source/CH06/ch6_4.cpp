#include <iostream>
using namespace std;

void add(int *A, int *B, int *C, int n);//4

int main ()
{
	int A[5] = {1,2,3,4,5}, B[5] = {6,7,8,9,10}, C[5] = {0}, n = 0;
	cout<<"A[] = {1,2,3,4,5}"<<endl;
	cout<<"B[] = {6,7,8,9,10}"<<endl;
	add(A,B,C,5);
	return 0;
}

void add(int *A, int *B, int *C, int n)
{
	int i;
	for(i = 0;i < n; i++){
		C[i] = A[i] + B[i];
	}
	cout<<"A + B = {";
	for(i = 0;i < n; i++){
		if(i == n-1)
			cout<<C[i];
		else
			cout<<C[i]<<",";
	}
	cout<<"}"<<endl;
}