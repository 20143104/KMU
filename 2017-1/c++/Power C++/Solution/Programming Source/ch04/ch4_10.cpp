#include <iostream>

using namespace std;

void print_menu();
void get_menu_number(int sel);
void hamburger();
void cheese_hamburger();
void sandwich();


int main(void)
{
	
	print_menu();
	

	return 0;
}

void print_menu()
{
	int sel = 0;
	
	cout<<"1. 햄버거"<<endl;
	cout<<"2. 치즈버거"<<endl;
	cout<<"3. 샌드위치"<<endl;
	cout<<"4. 종료"<<endl;
	cout<<"원하는 메뉴를 선택하시오."<<endl;
	cin>>sel;

	get_menu_number(sel);

}
void get_menu_number(int sel)
{
	switch(sel){
	case 1:
		hamburger();
		print_menu();
		break;
	case 2:
		cheese_hamburger();
		print_menu();
		break;
	case 3:
		sandwich();
		print_menu();
		break;
	case 4:
		return;
		break;
	default:
		print_menu();
		break;
	}
	
}
void hamburger()
{
	cout<<"1. 햄버거"<<endl;
}
void cheese_hamburger()
{
	cout<<"2. 치즈버거"<<endl;
}
void sandwich()
{
	cout<<"3. 샌드위치"<<endl;
}