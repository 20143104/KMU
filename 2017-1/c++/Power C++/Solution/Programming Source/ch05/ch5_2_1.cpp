#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int decimal = 0;
	int num[64] = {0}, count = 63, i; 

	cout<<"10진수를 입력하시오.: ";
	cin>>decimal;
	while(1){
		num[count] = decimal%2;
		decimal = decimal/2;
		if(decimal == 0){
			break;
		}
		else if(decimal == 1){
			count--;
			num[count] = 1;
			break;
			
		}
		count--;
	}
	for(i = count;i < 64; i++){
		cout<<num[i];
	}
	cout<<endl;
	return 0;
}