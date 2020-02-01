#include <iostream>

using namespace std;

long ipower(int n,int k);

int main()
{
	int k;

	cout<<"n^k "<<endl;
	
	for(k = 0;k <= 10; k++){
		cout<<ipower(3,k)<<endl;
	}
	return 0;
}
long ipower(int n,int k)
{
	int i;
	long temp;

	temp = 1;

	if(k == 0){
		return 1;
	}
	else{
		for(i = 0;i < k; i++){
			temp = temp*n;
		}
	}
	return temp;

}