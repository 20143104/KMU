#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class user
{
	int num;
	string name;
	string number;
	string email;
public:
	int get_userNum()
	{
		return num;
	}
	void set_user(int num, string name, string number, string email)
	{
		this->num = num;
		this->name = name;
		this->number = number;
		this->email = email;
	}
	void prt()
	{
		cout<<"��ȣ      �̸�         ��ȭ��ȣ       �̸��� �ּ�"<<endl;
		cout<<num<<"   "<<name<<"       "<<number<<"         "<<email<<endl;
	}
};

int main()
{
	user u[50];
	int num;
	string name,number,email;
	int i = 0;
	char ext;

	ofstream os;
	os.open("user.txt");
	if(os.fail()){
		cerr<< "���� ���� ����"<<endl;
		exit(1);
	}

	while(1)
	{
		cout<<"��ȣ�� �Է��ϼ��� : ";
		cin>>num;
		cout<<"�̸��� �Է��ϼ��� : ";
		cin>>name;
		cout<<"��ȭ��ȣ�� �Է��ϼ��� : ";
		cin>>number;
		cout<<"�̸����ּҸ� �Է��ϼ��� : ";
		cin>>email;
		u[i].set_user(num, name, number, email);
		os<<num<<"   "<<name<<"       "<<number<<"         "<<email<<endl;
		cout<<"���� �Ͻðڽ��ϱ�? (Y/N) ";
		cin>>ext;

		if( ext == 'Y' || ext == 'y')
			break;
		u[i].prt();
		i++;

	}

	int s_num;
	cout<<"��ȣ�� �Է��ϼ���";
	cin>>s_num;

	for(int j=0; j < i ; j++)
	{
		if (u[i].get_userNum() == s_num)
			u[i].prt();
	}
	
	return 0;


}
	

