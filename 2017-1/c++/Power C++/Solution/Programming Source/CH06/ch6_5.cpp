#include <iostream>
#include <ctime>
using namespace std;

void reverse(int *A, int n);//5
void reverse_menu();

int main ()
{
	int A[5] = {1,2,3,4,5}, n = 0;
	cout<<"A[] = {1,2,3,4,5}"<<endl;
	cout<<endl;
	reverse(A,5);
	return 0;
}

void reverse(int *A, int n)
{
	int i, temp = 0;
	for(i = 0;i < (n-1)/2; i++){
		temp = A[i];
		A[i] = A[(n-1)-i];
		A[(n-1)-i] = temp;
	}
	cout<<"A[] = {";
	for(i = 0;i < n; i++){
		if(i == n-1)
			cout<<A[i];
		else
			cout<<A[i]<<",";
	}
	cout<<"}"<<endl;
	
}