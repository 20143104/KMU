#include <iostream>

using namespace std;

int main()
{
	char sel;
	int width = 0, height = 0, radius = 0;

	cout<<"문자를 입력하세요 (R,T,C) : ";
	cin>>sel;

	switch(sel){

	case 'R':
		cout<<"밑변 길이, 높이를 입력하세요 :";
		cin>>width>>height;
		cout<<"사각형의 면적은 : "<<width*height<<endl;
		break;
	case 'T':
		cout<<"밑변 길이, 높이를 입력하세요 :";
		cin>>width>>height;
		cout<<"삼각형의 면적은 : "<<(width*height)/2<<endl;
		break;
	case 'C':
		cout<<"반지름을 입력하세요 :";
		cin>>radius;
		cout<<"원의 면적은 : "<<3.14*(radius*radius)<<endl;
		break;
	
	}

	return 0;
}
