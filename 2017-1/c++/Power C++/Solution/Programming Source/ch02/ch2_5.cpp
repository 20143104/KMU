#include <iostream>

using namespace std;

int main()
{
	int com = 0, clang = 0, eng = 0, math = 0;
	float ave = 0;

	cout<<"컴퓨터 개론 과목의 점수를 입력하시오.:";
	cin>>com;
	cout<<"C언어 프로그래밍 과목의 점수를 입력하시오.:";
	cin>>clang;
	cout<<"영어 과목의 점수를 입력하시오.:";
	cin>>eng;
	cout<<"일반 수학 과목의 점수를 입력하시오.:";
	cin>>math;

	ave = (com + clang + eng + math)/4.0;
	
	cout<<"평균점수는 "<<ave<<"점입니다."<<endl;
	
	
	

	return 0;

}