#include <stdio.h>
using namespace std;

int all_files;	// �ٸ� �ҽ� ���Ͽ����� ����� �� �ִ� ���� ����
static int this_file; // ������ �ҽ� ���Ͽ����� ����� �� �ִ� ���� ����
extern void sub();

int main()
{
	sub();
	cout << all_files << endl;
	return 0;
}

