#include <iostream>
using namespace std;

int main()
{
	double age =0, height=0, weight = 0;
	double coup = 0;

	cout<<"나이를 입력하세요 : ";
	cin>>age;
	cout<<"키를 입력하세요 : ";
	cin>>height;
	cout<<"체중을 입력하세요 : ";
	cin>>weight;

	height = height * 0.01;
	coup = weight / (height*height);

	if(age >=20 && age <=29){
		if( coup >=17.9 && coup < 18)
			cout<<"저체중입니다.^^;"<<endl;
		else if( coup >=18 && coup <=23)
			cout<<"표준체중입니다.^^;"<<endl;
		else if( coup >=24 && coup <30)
			cout<<"과체중입니다.^^;"<<endl;
		else if( coup >=30)
			cout<<"비만입니다. ^^;"<<endl;
		else 
			cout<<"범위에 없습니다."<<endl;
	}
	else if(age >=30 && age <=39){
		if( coup >=18.4 && coup < 18.5)
			cout<<"저체중입니다.^^;"<<endl;
		else if( coup >=18.5 && coup <= 24)
			cout<<"표준체중입니다.^^;"<<endl;
		else if( coup >=25 && coup <30)
			cout<<"과체중입니다.^^;"<<endl;
		else if( coup >=30)
			cout<<"비만입니다. ^^;"<<endl;
		else 
			cout<<"범위에 없습니다."<<endl;
	}
	else{
		cout<<"해당 나이에 대한 조건이 없습니다."<<endl;
	}
	return 0;
}
