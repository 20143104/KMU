#include <iostream>

using namespace std;

int main(void)
{
 	int n = 0, r = 0, i, p = 1;
 
 	cout<<"������ n���� r���� �Է��Ͻÿ� : ";
 	cin>>n>>r;
 	for(i = n;i >= r; i--){
 		p = p * i;
 	}
 	cout<<n<<"P"<<r<<"������ ���� "<<p<<"�Դϴ�."<<endl;
}
