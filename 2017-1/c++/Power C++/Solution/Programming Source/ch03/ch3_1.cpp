#include <iostream>
using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;     
	double slope1, slope2; //����
	
	cout<<"1��°�����Է��ϼ���(x1,y1) : ";
	cin>>x1>>y1;
	cout<<"2��°�����Է��ϼ���(x2,y2) : ";
	cin>>x2>>y2;
	cout<<"3��°�����Է��ϼ���(x3,y3) : ";
	cin>>x3>>y3;

	slope1 = (x1-x2)/(y1-y2);
	slope2 = (x1-x3)/(y1-y3);

	if( slope2 == slope1)
		cout<<"�˸�)�ﰢ�� ����� �����ϴ�."<<endl;
	else
		cout<<"�˸�)�ﰢ�� ����� �ֽ��ϴ�."<<endl;
	return 0;
}