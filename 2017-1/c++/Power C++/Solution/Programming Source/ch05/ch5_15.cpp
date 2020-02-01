#include <iostream>

using namespace std;

#define MAX_SIZE 3

void scalar_mult(int a[MAX_SIZE][MAX_SIZE],int scalar);
void sub(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE]);
void transpose(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE]);

int main(void)
{
	int a[MAX_SIZE][MAX_SIZE] = {{1,2,3},{4,5,6,},{7,8,9}}, b[MAX_SIZE][MAX_SIZE] = {{1,1,1},{1,1,1},{1,1,1}};
	cout<<"a[3][3]"<<endl;
	for(int i = 0;i < MAX_SIZE; i++){
		for(int j = 0;j < MAX_SIZE; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;;
	}
	cout<<"b[3][3]"<<endl;
	for(i = 0;i < MAX_SIZE; i++){
		for(int j = 0;j < MAX_SIZE; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;;
	}
	scalar_mult(a,2);
	sub(a,b);
	for(i = 0;i < MAX_SIZE; i++){
		for(int j = 0;j < MAX_SIZE; j++){
			b[i][j] = a[i][j];
		}
	
	}
	transpose(a,b);

	return 0;
}
void scalar_mult(int a[MAX_SIZE][MAX_SIZE],int scalar)
{
	cout<<"scalar_mult(a,2)"<<endl;
	for(int i = 0;i < MAX_SIZE; i++){
		for(int j = 0;j < MAX_SIZE; j++){
			a[i][j] *= scalar;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;;
	}
}
void sub(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE])
{
	cout<<"sub(a,b)"<<endl;
	for(int i = 0;i < MAX_SIZE; i++){
		for(int j = 0;j < MAX_SIZE; j++){
			a[i][j] -= b[i][j];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;;
	}
	
}
void transpose(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE])
{
	int i,j;
	cout<<"transpose(a,b)"<<endl;

	for(i = 0;i < MAX_SIZE; i++){
		for(int j = 0;j < MAX_SIZE; j++){
			a[i][j] = b[j][i];
		}
	}
	for(i = 0;i < MAX_SIZE; i++){
		for(int j = 0;j < MAX_SIZE; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}