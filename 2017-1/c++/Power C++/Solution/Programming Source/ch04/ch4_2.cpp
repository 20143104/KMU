#include <iostream>

using namespace std;
bool prime(int n);

int main()
{
	int i = 0;

	for(i = 1;i <= 100; i++){
		if(prime(i) == true){
			cout<<i<<" ";
		}
	}

	cout<<endl;

	return 0;
}
bool prime(int n)
{
	int i;
	if(n == 1){
		return false;
	}
	else{
		for(i = 2;i < n; i++){
			if(n%i == 0){
				return false;
			}
		}
		return true;
	}
	
}