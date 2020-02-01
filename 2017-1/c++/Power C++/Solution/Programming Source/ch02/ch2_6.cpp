#include <iostream>

using namespace std;

int main()
{
	float weight = 0, pound = 0, ounce = 0;

	cout<<"무게를 입력하시오.:";
	cin>>weight;

	pound = weight*2.2;
	ounce = pound*16;

	cout<<weight<<"킬로그램은 "<<pound<<" 파운드입니다."<<endl;
	cout<<weight<<"킬로그램은 "<<ounce<<" 온스입니다."<<endl;

	return 0;
}