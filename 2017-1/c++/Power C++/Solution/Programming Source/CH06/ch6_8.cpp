#include <iostream>
#define MAX_SIZE 10

using namespace std;

void get_sum_diff(int A[], int n, int *p_sum, int *p_diff);

int main ()
{
	int a[MAX_SIZE] = {0}, n =0, sum = 0, diff = 0;
	int *p_sum = &sum;
	int *p_diff = &diff;

	cout<<"두 정수를 입력하시오 : ";
	cin>>a[0]>>a[1];
	
	get_sum_diff(a,2,p_sum,p_diff);

	cout<<"두 정수의 합 : "<<sum<<endl;
	cout<<"두 정수의 차 : "<<diff<<endl;

	return 0;
}
void get_sum_diff(int A[], int n, int *p_sum, int *p_diff)
{
	
	*p_sum = A[0] + A[1];
	*p_diff = A[0] - A[1];

}