#include <iostream>
using namespace std

int main()
{
	const int STUDENTS=5;
	int grade[STUDENTS];
	int i, max;
	
	for(i = 0; i < STUDENTS; i++)
	{
		cout << "������ �Է��Ͻÿ�: ";
		cin >> grade[i];
	}
	
	max = grade[0];

	for(i = 1; i < STUDENTS; i++)
	{
		if( grade[i] > max )
			max = grade[i];
	}
	cout << "�ִ밪�� " << max << ���Դϴ�." << endl;

	return 0;
}
