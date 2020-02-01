#include <iostream>
#define ARR_SIZE 5

using namespace std;

int array_equal(int a[], int b[], int size);

int main()
{
	int i;
	int a[ARR_SIZE] = {1,2,3,4,5};
	int b[ARR_SIZE] = {1,2,3,4,5};
	
	cout<<"배열 A: ";
	for(i=0; i < ARR_SIZE; i++)
		cout<< a[i] <<"\t";
	cout<<endl;

	cout<<"배열 B: ";
	for(i=0; i < ARR_SIZE; i++)
		cout<< b[i] <<"\t";
	cout<<endl;

	if( array_equal(a,b, ARR_SIZE) == 1){
		cout<<"배열 A와 배열 B의 전체 원소는 같습니다. "<<endl;
	}
	else{
		cout<<"배열 A와 배열 B의 전체 원소는 같지 않습니다. "<<endl;
	}
	return 0;

}

int array_equal(int a[], int b[], int size)
{
	int i;

	for(i=0; i<size; i++){
		if(a[i] != b[i])
			return 0;
	}

	return 1;
}


