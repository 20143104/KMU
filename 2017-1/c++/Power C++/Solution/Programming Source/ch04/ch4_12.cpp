#include <iostream>

using namespace std;

void save(int amount);
void draw(int amount);
void menu();

int money;

int main()
{
	menu();
	return 0;
}
void menu()
{
	int sel = 0, amount = 0;

	while(1){
		cout<<"1. ����"<<endl;
		cout<<"2. ���� ����"<<endl;
		cout<<"-1. ����"<<endl;
		cout<<">>"<<endl;
		cin>>sel;

		if(sel == 1){
			cout<<"�󸶸� �����Ͻðڽ��ϱ�?: ";
			cin>>amount;
			save(amount);
		}
		else if(sel == 2){
			cout<<"�󸶸� �����Ͻðڽ��ϱ�?: ";
			cin>>amount;
			draw(amount);
		}
		else if(sel == -1){
			break;
		}
		cout<<"���ݱ��� ��������� "<<money<<"�� �Դϴ�."<<endl;
	}

}
void save(int amount)
{
	money += amount;
}
void draw(int amount)
{
	money -= amount;

}