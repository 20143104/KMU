#include <iostream>

using namespace std;

void Incryption_str(char *str); 
void Decryption_str(char *str);

int main()
{
	char str[200];
	int num;
	while(1)
	{
		cout<<"1. 암호화"<<endl;
		cout<<"2. 복호화"<<endl;
		cout<<"3. 종료"<<endl;
		cout<<"메뉴를 선택하시오: ";
		cin>>num;

		fflush(stdin);

		switch(num){
			case 1 :
				cout<<"문자열을 입력하시오: ";
				cin.getline(str, 200);
				cout<<"암호화된 문자열: ";	
				Incryption_str(str);
				cout<<str<<endl;
				break;
			case 2 :
				cout<<"복호화된 문자열: ";
				Decryption_str(str);
				cout<<str<<endl;
				break;
			case 3 :
				return 0;
				break;
			default :
				cout<<"잘못 입력하셨습니다. "<<endl;
				break;

		}
	}

	return 0;
}

void Incryption_str(char *str)
{
	int i=0;

	while(str[i]!=NULL){
		if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))  
			str[i] = str[i] + 3;  
		i++;
	}
}

void Decryption_str(char *str)
{
	int i=0;
	while(str[i]!=NULL)
	{
		if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
			str[i] = str[i] - 3;
		i++;
	}
}x
