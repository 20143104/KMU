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
		cout<<"번호      이름         전화번호       이메일 주소"<<endl;
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
		cerr<< "파일 오픈 실패"<<endl;
		exit(1);
	}

	while(1)
	{
		cout<<"번호를 입력하세요 : ";
		cin>>num;
		cout<<"이름를 입력하세요 : ";
		cin>>name;
		cout<<"전화번호를 입력하세요 : ";
		cin>>number;
		cout<<"이메일주소를 입력하세요 : ";
		cin>>email;
		u[i].set_user(num, name, number, email);
		os<<num<<"   "<<name<<"       "<<number<<"         "<<email<<endl;
		cout<<"종료 하시겠습니까? (Y/N) ";
		cin>>ext;

		if( ext == 'Y' || ext == 'y')
			break;
		u[i].prt();
		i++;

	}

	int s_num;
	cout<<"번호를 입력하세요";
	cin>>s_num;

	for(int j=0; j < i ; j++)
	{
		if (u[i].get_userNum() == s_num)
			u[i].prt();
	}
	
	return 0;


}
	

