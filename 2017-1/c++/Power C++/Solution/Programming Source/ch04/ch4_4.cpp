#include <iostream>
#include <cmath>

using namespace std;

double dist_2d(double x1, double y1, double x2, double y2);

int main()
{
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cout<<"<<좌표값을 입력하시오.>>"<<endl;
	cout<<"x1의 값을 입력하시오: ";
	cin>>x1;
	cout<<"y1의 값을 입력하시오: ";
	cin>>y1;
	cout<<"x2의 값을 입력하시오: ";
	cin>>x2;
	cout<<"y2의 값을 입력하시오: ";
	cin>>y2;

	cout<<"두점간의 거리는 "<<dist_2d(x1,y1,x2,y2)<<"입니다."<<endl;


	return 0;
}

double dist_2d(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}