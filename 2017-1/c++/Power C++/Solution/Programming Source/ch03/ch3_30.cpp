#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	char input;
	int count = 0;

	input = _getch();

	while(input != 13){
		if(input == 'a'){
			count++;
		}
		cout<<input;
		input = _getch();
	}

	cout<<endl<<"�Է��� ���� �� a�� ������ "<<count<<"�� �Դϴ�."<<endl;
}
