// ���ڿ��� ���̸� ���ϴ� ���α׷�
#include <iostream>
using namespace std;

int main()
{
	char str[30] = "C++ language is easy";
	int i = 0;
	
	while(str[i] != 0)
		i++;
	cout << "���ڿ� "<< str << "�� ���̴� " << i << "�Դϴ�." << endl;

	return 0;
}
