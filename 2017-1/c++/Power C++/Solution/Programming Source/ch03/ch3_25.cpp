#include <iostream>

using namespace std;

int main()
{
	double eff = 0.0, fuel = 0.0, dist = 0.0;
	char conti = 'Y';

	while(1){
		cout<<"������ ���� �Է��Ͻÿ�(l) : ";
		cin>>fuel;
		cout<<"������ �Ÿ��� �Է��ϼ���(km) : ";
		cin>>dist;
		eff = dist/fuel;
		cout<<"�����  "<<eff<<"km/l �Դϴ�."<<endl;
		cout<<"�ٽ� ����ϰڽ��ϱ�?(Y/N) : ";	
		cin>>conti;
		if(conti == 'N' || conti == 'n')
			break;
	}

	return 0;
}
