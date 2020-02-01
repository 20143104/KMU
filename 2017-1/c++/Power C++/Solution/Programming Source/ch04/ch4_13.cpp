#include <iostream>

using namespace std;
void show_digit(int x);

int main()
{
	int x;
	cout<<"정수를 입력하시오: ";
	cin>>x;
	show_digit(x);
	return 0;
}
void show_digit(int x)
{
	if(x!=0){
        show_digit(x/10);
        cout<<x%10<<" ";

    }

    return;
}