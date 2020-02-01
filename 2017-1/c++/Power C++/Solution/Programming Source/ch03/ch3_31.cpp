#include <iostream>

using namespace std;

int main(void)
{
 	int n = 0, r = 0, i, p = 1;
 
 	cout<<"순열의 n값과 r값을 입력하시오 : ";
 	cin>>n>>r;
 	for(i = n;i >= r; i--){
 		p = p * i;
 	}
 	cout<<n<<"P"<<r<<"순열의 값은 "<<p<<"입니다."<<endl;
}
