#include <iostream>

using namespace std;
void copy(int *A, int *B, int n);

int main ()
{	
	int A[] = {1,2,3,4,5}, B[] = {6,7,8,9,10}, n = 0;
	cout<<"A[] = {1,2,3,4,5}"<<endl;
	cout<<"B[] = {6,7,8,9,10}"<<endl;
	cout<<endl;
	copy(A,B,5);
	return 0;
}
void copy(int *A, int *B, int n)
{
	int *C = NULL, i;
	C = B;
	B = A;
	A = C;
	
	cout<<"A[] = {";
	for(i = 0;i < n; i++){
		if(i == n-1)
			cout<<A[i];
		else
			cout<<A[i]<<",";
		
	}
	cout<<"}"<<endl;
	cout<<"B[] = {";
	for(i = 0;i < n; i++){
		if(i == n-1)
			cout<<B[i];
		else
			cout<<B[i]<<",";
	}
	cout<<"}"<<endl;
}