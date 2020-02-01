#include <iostream>
#include <cmath>
using namespace std;

#define RAD_TO_DEG (45.0/atan(1))

int main()
{
	double w, h, r, theta;
	
	cout << "�غ��� �Է��Ͻÿ�: ";
	cin >> w;

	cout << "���̸� �Է��Ͻÿ�: ";
	cin >> h;
	
	r = sqrt(w * w + h * h);
	theta = RAD_TO_DEG * atan2(h, w);
	
	cout << "����= " << r << " ����= " << theta << endl;
	
	return 0;
