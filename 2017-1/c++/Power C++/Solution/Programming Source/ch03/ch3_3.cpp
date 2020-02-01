#include <iostream>

using namespace std;

int main()
{
	int num = 0, sum = 0;
	int i = 0, b = 1;
	cout<< " 2진수를 입력하세요 : ";
	cin>>num;

	for(i = num ; i > 0 ; i = i /10){
		sum = sum + (i % 10 * b);
		b = b * 2;
	}
	cout<<" 2진수 -> 10진수 : "<<sum<<endl;
	return 0;
}
