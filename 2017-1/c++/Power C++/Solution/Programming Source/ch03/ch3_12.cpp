#include <iostream>
using namespace std;

int main()
{
	double age =0, height=0, weight = 0;
	double coup = 0;

	cout<<"���̸� �Է��ϼ��� : ";
	cin>>age;
	cout<<"Ű�� �Է��ϼ��� : ";
	cin>>height;
	cout<<"ü���� �Է��ϼ��� : ";
	cin>>weight;

	height = height * 0.01;
	coup = weight / (height*height);

	if(age >=20 && age <=29){
		if( coup >=17.9 && coup < 18)
			cout<<"��ü���Դϴ�.^^;"<<endl;
		else if( coup >=18 && coup <=23)
			cout<<"ǥ��ü���Դϴ�.^^;"<<endl;
		else if( coup >=24 && coup <30)
			cout<<"��ü���Դϴ�.^^;"<<endl;
		else if( coup >=30)
			cout<<"���Դϴ�. ^^;"<<endl;
		else 
			cout<<"������ �����ϴ�."<<endl;
	}
	else if(age >=30 && age <=39){
		if( coup >=18.4 && coup < 18.5)
			cout<<"��ü���Դϴ�.^^;"<<endl;
		else if( coup >=18.5 && coup <= 24)
			cout<<"ǥ��ü���Դϴ�.^^;"<<endl;
		else if( coup >=25 && coup <30)
			cout<<"��ü���Դϴ�.^^;"<<endl;
		else if( coup >=30)
			cout<<"���Դϴ�. ^^;"<<endl;
		else 
			cout<<"������ �����ϴ�."<<endl;
	}
	else{
		cout<<"�ش� ���̿� ���� ������ �����ϴ�."<<endl;
	}
	return 0;
}
