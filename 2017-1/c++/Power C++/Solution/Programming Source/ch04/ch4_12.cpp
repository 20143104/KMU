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
		cout<<"1. 저축"<<endl;
		cout<<"2. 예금 인출"<<endl;
		cout<<"-1. 종료"<<endl;
		cout<<">>"<<endl;
		cin>>sel;

		if(sel == 1){
			cout<<"얼마를 저축하시겠습니까?: ";
			cin>>amount;
			save(amount);
		}
		else if(sel == 2){
			cout<<"얼마를 인출하시겠습니까?: ";
			cin>>amount;
			draw(amount);
		}
		else if(sel == -1){
			break;
		}
		cout<<"지금까지 총저축액은 "<<money<<"원 입니다."<<endl;
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