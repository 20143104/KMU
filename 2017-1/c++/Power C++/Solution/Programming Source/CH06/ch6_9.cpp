#include <iostream>
#define MAX_SIZE 10

using namespace std;

void get_stat(double A[], double *p_avg, double *p_sum, double *p_max);

int main ()
{
	double a[MAX_SIZE] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.3}, sum = 0, avg = 0, max = 0;
	double *p_sum = &sum;
	double *p_avg = &avg;
	double *p_max = &max;

	cout<<"A[] = { ";
	for(int i = 0;i < MAX_SIZE;i++){
		cout<<a[i]<<" ";
	}
	cout<<"}"<<endl;
	
	get_stat(a,p_avg,p_sum,p_max);

	cout<<"ÃÑÇÕ : "<<sum<<endl;
	cout<<"ÃÑ Æò±Õ : "<<avg<<endl;
	cout<<"ÃÖ´ë°ª : "<<max<<endl;

	return 0;
}
void get_stat(double A[], double *p_avg, double *p_sum, double *p_max)
{
	
	for(int i = 0;i < MAX_SIZE;i++){
		*p_sum += A[i];
		if(*p_max < A[i]){
			*p_max = A[i];
		}
	}
	*p_avg = (*p_sum) / MAX_SIZE;
}
