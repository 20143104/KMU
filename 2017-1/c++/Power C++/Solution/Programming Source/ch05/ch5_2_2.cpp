#include <iostream>
#include <cmath>

using namespace std;

void change_number(int n, int sel);

int main(void)
{
	int num = 0, sel = 0; 

	cout<<"������ �Է��Ͻÿ�.: ";
	cin>>num;
	cout<<"��ȯ�� ������ �Է��Ͻÿ�.: ";
	cin>>sel;
	change_number(num,sel);

	return 0;
}

void change_number(int n, int sel)
{
	int num[64] = {0}, count = 63, i;
	while(1){
		num[count] = n%sel;
		n = n/sel;
		if(n == 0){
			break;
		}
		else if(n == 1){
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
}