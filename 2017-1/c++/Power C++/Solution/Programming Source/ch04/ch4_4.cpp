#include <iostream>
#include <cmath>

using namespace std;

double dist_2d(double x1, double y1, double x2, double y2);

int main()
{
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cout<<"<<��ǥ���� �Է��Ͻÿ�.>>"<<endl;
	cout<<"x1�� ���� �Է��Ͻÿ�: ";
	cin>>x1;
	cout<<"y1�� ���� �Է��Ͻÿ�: ";
	cin>>y1;
	cout<<"x2�� ���� �Է��Ͻÿ�: ";
	cin>>x2;
	cout<<"y2�� ���� �Է��Ͻÿ�: ";
	cin>>y2;

	cout<<"�������� �Ÿ��� "<<dist_2d(x1,y1,x2,y2)<<"�Դϴ�."<<endl;


	return 0;
}

double dist_2d(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}