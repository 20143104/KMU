#include <iostream>

using namespace std;

int main()
{
	int x,y,z, ans=0;
	cout<<"3���� ������ �Է��ϼ��� (3 4 5) : ";
	cin>>x>>y>>z;
	if( x > y){
		if(y > z)
			ans = z;
		else
			ans = y;
	}
	else{
		if( x > z)
			ans = z;
		else
			ans = x;
	}
	cout<<"���� ���� �� : "<<ans<<endl;
}
