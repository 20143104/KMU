#include <iostream>
#define SIZE 50

using namespace std;

bool palind_check(char *st, int size);

int main()
{
	char str[SIZE];

	cout<<"���ڿ��� �Է��ϼ��� : ";
	cin.getline(str, SIZE);

	if(palind_check(str, SIZE) == 1)
		cout<< "ȸ���Դϴ�. "<<endl;
	else
		cout<< "ȸ���� �ƴմϴ�."<<endl;

	return 0;
}

bool palind_check(char *st, int size)
{
	int i, n;

	n = strlen(st) - 1;
	strlwr(st);

	for(i=0; n>0; i++){
		if(st[i] != st[n])
			return 0;
		n--;
	}
	return 1;
}
