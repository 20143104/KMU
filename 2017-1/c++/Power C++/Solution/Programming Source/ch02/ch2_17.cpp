#include <iostream>

using namespace std;

int main()
{
	int x = 0, y = 0, area = 0;

	

	cout<<"x좌표를 입력하시오: ";
	cin>>x;
	cout<<"y좌표를 입력하시오: ";
	cin>>y;
	
	(x>0 && y>0) ? (area=1): ((x<0 && y>0) ? (area=2) : ((x<0 && y<0) ? (area=3) : (area=4)));

	cout<<"좌표는 "<<area<<"사분면입니다."<<endl;
	
		

	return 0;
}