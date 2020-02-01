#include <iostream>
#include <string>

using namespace std;

class MyWorld
{
private:
	string name;
	MyWorld *myfrd;
	int loveP;

public:
	MyWorld(){
		name = "";
		myfrd = NULL;
		loveP = 0;
	};
	MyWorld(string n, MyWorld *my, int l):name(n), myfrd(my), loveP(l){ };
	void setLoveP()
	{
		loveP++;
	}
	void setName(string n)
	{
		name = n;
	}
	void setMyFrd(MyWorld *my)
	{
		myfrd = my;
	}

	int getLoveP()
	{
		return loveP;
	}
	string getName()
	{
		return name;
	}
	MyWorld* setMyFrd()
	{
		return myfrd;
	}
	~MyWorld()
	{
		delete myfrd;
	}
	void print()
	{
		cout<<"======================"<<endl;
		cout<<"�̸� : " <<name<<endl;
		if(myfrd == NULL)
			cout<<"���� : ���� "<<endl;
		else
			cout<<"���� : " <<myfrd->name<<endl;
		cout<<"�α⵵ : "<<loveP<<endl;
		cout<<"======================"<<endl;
	}
};
	
int main()
{
	int i, j;
	string n[4]={"CSK", "BHJ", "YJS", "KHD"};
	string tmp;
	MyWorld P[4];

	for(i=0; i < 4; i++)
	{
		P[i].setName(n[i]);
	}

	for(i=0; i < 4; i++)
	{
		P[i].print();
		cout<<"======================��"<<endl;
		cout<<"ģ���� �Է��ϼ��� : ";
		cin>>tmp;

		for(j=0; j < 4; j++){
			if(tmp == P[j].getName())
			{
				P[i].setMyFrd(&P[j]);
				P[j].setLoveP();
				break;
			}
		}
	}

	for(i=0; i < 4 ; i++)
		P[i].print();

	return 0;
}
	