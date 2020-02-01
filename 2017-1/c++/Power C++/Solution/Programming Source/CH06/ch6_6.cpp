#include <iostream>
#define MAX_SIZE 10

using namespace std;

int sum_range(int *pstart, int *pend);
void print(int a[],int size);

int main ()
{
	int a[MAX_SIZE] = {1,2,3,4,5,6,7,8,9,10};
	int start,end;
	int *pstart, *pend;
	print(a,MAX_SIZE);
	cout<<"½ÃÀÛ : ";
	cin>>start;
	cout<<"³¡ : ";
	cin>>end;
	
	pstart = a+(start-1);
	pend = a+(end-1);

	cout<<sum_range(pstart,pend)<<endl;

	return 0;
}

int sum_range(int *pstart, int *pend)
{

	int sum = 0;
	while(pstart <= pend){
		sum += *pstart;
		pstart++;
	}
	return sum;
}
void print(int a[],int size)
{
	int i = 0;
	cout<<"A[] = { ";
	for(i = 0;i < size;i++){
		cout<<a[i]<<" ";
	}
	cout<<"}"<<endl;
}