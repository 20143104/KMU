#include <iostream>

using namespace std;

int main()
{
	int hour = 0, min = 0, second = 0, result = 0;
	

	cout<<"시간을 입력하시오.(시):";
	cin>>hour;
	cout<<"시간을 입력하시오.(분):";
	cin>>min;
	cout<<"시간을 입력하시오.(초):";
	cin>>second;
	
	result = hour*3600 + min*60 + second;

	cout<<hour<<"시간 "<<min<<"분 "<<second<<"초는 "<<result<<" 초입니다."<<endl;
	

	return 0;
}