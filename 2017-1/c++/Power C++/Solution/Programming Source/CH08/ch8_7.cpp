#include <iostream>
#define PI 3.141592

using namespace std;

double CircleArea(double);

int main()
{
	bool state = true;
	double radius = 0;
	char con;
	while(state){
		cout<<"���� �������� �Է��Ͻÿ� : ";
		cin>>radius;
		cout<<"���� �������� "<<CircleArea(radius)<<"�Դϴ�."<<endl;
		cout<<"��� �Ͻðڽ��ϱ�?(Y/N)";
		cin>>con;
		if(con == 'Y' || con == 'y'){
			state = true;
		}
		else if(con == 'N' || con == 'n'){
			state = false;
		}
	}

	return 0;
}

double CircleArea(double r)
{
	return r*r*PI;
}