#include <iostream>
#define SIZE 100
using namespace std;

int isalpha(char *);

int main()
{
	char str[SIZE];

	cout<<"���� ���ڿ��� �Է��ϼ��� : ";
	cin.getline(str, SIZE); // cin�� ���鹮�ڸ� �����ϱ� ������ getline()�� ���
	cout<<"���ܾ��� ������ : "<<isalpha(str)<<endl;

	
}

int isalpha(char *st)
{
	int i;
	int cnt = 1;

	for(i=0; i< SIZE; i++){
		if(st[i] == NULL)
			break;
		else if(st[i] == ' ')
			cnt++;
	}
	return cnt;

}
