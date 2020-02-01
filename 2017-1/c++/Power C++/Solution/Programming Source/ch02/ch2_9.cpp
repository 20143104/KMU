#include <iostream>

using namespace std;

int main()
{
	int num = 0, thousand = 0, hundred = 0, ten = 0, one = 0;
	

	cout<<"정수를 입력하시오.:";
	cin>>num;
	
	thousand = num / 1000;
	hundred = (num-thousand*1000)/100;
	ten = (num-thousand*1000-hundred*100)/10;
	one = (num-thousand*1000-hundred*100-ten*10);

	cout<<"천의 자리: "<<thousand<<endl;
	cout<<"백의 자리: "<<hundred<<endl;
	cout<<"십의 자리: "<<ten<<endl;
	cout<<"일의 자리: "<<one<<endl;	

	return 0;
}