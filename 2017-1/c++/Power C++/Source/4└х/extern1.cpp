#include <iostream>
using namespace std;

int x;			// ���� ����
extern int y;		// ���� �ҽ� ������ �޺κп� ����� ����
extern int z;		// �ٸ� �ҽ� ������ ����

int main()
{
	extern int x;    // ���� ���� x�� �����Ѵ�. ����ȴ�. 
	
	x = 10;
	y = 20;
	z = 30;	

	return 0;
}

int y;		// ���� ����
