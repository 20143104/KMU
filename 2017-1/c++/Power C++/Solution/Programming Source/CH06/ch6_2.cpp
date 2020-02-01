#include <iostream>
using namespace std;
void print(int *A, int n);

int main ()
{	
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, n = 20;
	print(A,n);
	return 0;
}

void print(int *A, int n)
{
	int i;
	cout<<"A[] = { ";
	for(i = 0;i < n; i++){
		cout<<A[i]<<" ";
	}
	cout<<"}"<<endl;
}
