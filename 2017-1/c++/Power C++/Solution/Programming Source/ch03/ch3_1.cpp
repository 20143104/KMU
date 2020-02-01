#include <iostream>
using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;     
	double slope1, slope2; //기울기
	
	cout<<"1번째점을입력하세요(x1,y1) : ";
	cin>>x1>>y1;
	cout<<"2번째점을입력하세요(x2,y2) : ";
	cin>>x2>>y2;
	cout<<"3번째점을입력하세요(x3,y3) : ";
	cin>>x3>>y3;

	slope1 = (x1-x2)/(y1-y2);
	slope2 = (x1-x3)/(y1-y3);

	if( slope2 == slope1)
		cout<<"알림)삼각형 만들수 없습니다."<<endl;
	else
		cout<<"알림)삼각형 만들수 있습니다."<<endl;
	return 0;
}