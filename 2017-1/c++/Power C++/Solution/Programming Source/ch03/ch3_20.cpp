#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double count = 0, arith = 0, geon = 0, harmo = 0, x = 0; // ���, ����, ��ȭ ���
	int n;

	for(n=0; n<=count; n++){
		cout<<"x"<<n+1<<"���� �����͸� �Է��ϼ��� : ";
		cin>>x;

		if(x<0)
			break;
		count++;

		arith = arith + x;
		geon = geon + (x*x);
		harmo = harmo + (1/x);

	}
	arith = arith/count; //���
	geon = sqrt(geon); //��ȭ
	harmo = count/harmo;

	cout<<" ������ = "<<arith<<endl;
	cout<<" ������� = "<<geon<<endl;
	cout<<" ��ȭ��� = "<<harmo<<endl;
	
	return 0;
}
