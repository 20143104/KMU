#include <iostream>

using namespace std;

int main(void)
{
 	int fibo[22] = {0,1}, i;
 
 	for(i = 0;i < 20; i++){
 		cout<<fibo[i]<<" ";
 		fibo[i+2] = fibo[i] + fibo[i+1];
 	}
 	cout<<endl;
}