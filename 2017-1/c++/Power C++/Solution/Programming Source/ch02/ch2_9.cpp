#include <iostream>

using namespace std;

int main()
{
	int num = 0, thousand = 0, hundred = 0, ten = 0, one = 0;
	

	cout<<"������ �Է��Ͻÿ�.:";
	cin>>num;
	
	thousand = num / 1000;
	hundred = (num-thousand*1000)/100;
	ten = (num-thousand*1000-hundred*100)/10;
	one = (num-thousand*1000-hundred*100-ten*10);

	cout<<"õ�� �ڸ�: "<<thousand<<endl;
	cout<<"���� �ڸ�: "<<hundred<<endl;
	cout<<"���� �ڸ�: "<<ten<<endl;
	cout<<"���� �ڸ�: "<<one<<endl;	

	return 0;
}