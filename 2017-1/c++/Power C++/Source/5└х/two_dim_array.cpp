#include <iostream>
using namespace std;

int main()
{
	int s[3][5];		// 2���� �迭 ����
	int i, j;		// 2���� �ε��� ����
	int value = 0;	// �迭 ���ҿ� ����Ǵ� ��
	
	for(i=0;i<3;i++)	
		for(j=0;j<5;j++)	
			s[i][j] = value++;

	for(i=0;i<3;i++)	
		for(j=0;j<5;j++)	
			cout << s[i][j];
	return 0;
}
