#include <iostream>

using namespace std;
void show_digit(int x);

int main()
{
	int x;
	cout<<"������ �Է��Ͻÿ�: ";
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