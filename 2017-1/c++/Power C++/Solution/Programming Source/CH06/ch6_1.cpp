#include <iostream>
#include <ctime>

using namespace std;

void fill(int *A, int n);

int main ()
{	
	srand(time(NULL));
	int A[10], n = 0;
	cout<<"������ ���� ����: ";
	cin>>n;
	fill(A,n);
	return 0;
	
}

void fill(int *A, int n)
{
	int i;
	for(i = 0;i < 10; i++){
		A[i] = rand()%n;
		cout<<A[i]<<"  ";
	}
	cout<<endl;
}