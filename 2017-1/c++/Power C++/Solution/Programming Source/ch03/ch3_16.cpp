#include <iostream>

using namespace std;

int main()
{
	int num=0;
	int i=0, count=1, condi=0;

	cout<<"정수를 입력하세요 : ";
	cin>>num;

	for(i = num; i >= 10; i = i/10)
		count = count * 10;

	while(count >= 1){
		condi = num/count;
		switch(condi){
		case 0:
			cout<<"zero ";
			break;
		case 1:
			cout<<"one ";
			break;
		case 2:
			cout<<"two ";
			break;
		case 3:
			cout<<"three ";
			break;
		case 4:
			cout<<"four ";
			break;
		case 5:
			cout<<"five ";
			break;
		case 6:
			cout<<"six ";
			break;
		case 7:
			cout<<"seven ";
			break;
		case 8:
			cout<<"eight ";
			break;
		case 9:
			cout<<"nine ";
			break;
		default:
			break;
		}
		num = num % count;
		count = count / 10;
	}
	
	cout<<endl;
	return 0;
}
