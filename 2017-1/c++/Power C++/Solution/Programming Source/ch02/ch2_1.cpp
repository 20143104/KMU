#include <iostream>

using namespace std;

int main()
{
	short height = 0, lenth = 0, width = 0;
	int cubage = 0;

	cout<<"상자의 높이를 입력하시오:";
	cin>>height;
	cout<<"상자의 길이를 입력하시오:";
	cin>>lenth;
	cout<<"상자의 너비를 입력하시오:";
	cin>>width;

	cubage = height*lenth*width;

	cout<<"상자의 체적은 "<<cubage<<"입니다."<<endl;

	return 0;
}