#include <iostream>

#define MAX 100

using namespace std;

int main(void)
{
	int count = 0, check = 0, i, j;
	
	for(i = 2;i <= MAX; i++){
		count = 0;
		for(j = 1;j <= i; j++){
			if(i%j == 0){
				count++;
			}
		}
		if(count == 2){
			cout<<"["<<i<<"]";
			cout<<endl;
			check++;
		}
	}
	return 0;
}
