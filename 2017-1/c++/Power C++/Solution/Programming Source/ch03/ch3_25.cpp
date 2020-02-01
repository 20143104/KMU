#include <iostream>

using namespace std;

int main()
{
	double eff = 0.0, fuel = 0.0, dist = 0.0;
	char conti = 'Y';

	while(1){
		cout<<"연료의 양을 입력하시오(l) : ";
		cin>>fuel;
		cout<<"주행한 거리를 입력하세요(km) : ";
		cin>>dist;
		eff = dist/fuel;
		cout<<"연비는  "<<eff<<"km/l 입니다."<<endl;
		cout<<"다시 계산하겠습니까?(Y/N) : ";	
		cin>>conti;
		if(conti == 'N' || conti == 'n')
			break;
	}

	return 0;
}
