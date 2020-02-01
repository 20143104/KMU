#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double count = 0, arith = 0, geon = 0, harmo = 0, x = 0; // 산술, 기하, 조화 평균
	int n;

	for(n=0; n<=count; n++){
		cout<<"x"<<n+1<<"값의 데이터를 입력하세요 : ";
		cin>>x;

		if(x<0)
			break;
		count++;

		arith = arith + x;
		geon = geon + (x*x);
		harmo = harmo + (1/x);

	}
	arith = arith/count; //산술
	geon = sqrt(geon); //조화
	harmo = count/harmo;

	cout<<" 산술평균 = "<<arith<<endl;
	cout<<" 기하평균 = "<<geon<<endl;
	cout<<" 조화평균 = "<<harmo<<endl;
	
	return 0;
}
