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
		cout<<"1. ��ȣȭ"<<endl;
		cout<<"2. ��ȣȭ"<<endl;
		cout<<"3. ����"<<endl;
		cout<<"�޴��� �����Ͻÿ�: ";
		cin>>num;

		fflush(stdin);

		switch(num){
			case 1 :
				cout<<"���ڿ��� �Է��Ͻÿ�: ";
				cin.getline(str, 200);
				cout<<"��ȣȭ�� ���ڿ�: ";	
				Incryption_str(str);
				cout<<str<<endl;
				break;
			case 2 :
				cout<<"��ȣȭ�� ���ڿ�: ";
				Decryption_str(str);
				cout<<str<<endl;
				break;
			case 3 :
				return 0;
				break;
			default :
				cout<<"�߸� �Է��ϼ̽��ϴ�. "<<endl;
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
