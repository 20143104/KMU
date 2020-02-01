#include <iostream>

using namespace std;

#define MAX_SIZE 100

int main(void)
{
	int sieve[MAX_SIZE] = {0}, i,j;

	for(i = 2;i < MAX_SIZE; i++){
		if(sieve[i] == 0){
			for(j = i * 2; j < MAX_SIZE; j = i + j ){
				sieve[j] = 1;
			}	
		}
	}
	for(i = 2;i < MAX_SIZE; i++){
		if(sieve[i] == 0){
			cout<<i<<"\t";
		}
	}
	cout<<endl;

	return 0;
}
