#include <iostream>
using namespace std;

int main() 
{ 
	int *pi; 	// ���� �޸𸮸� ����Ű�� ������

	pi = new int; 	// �� ���� �޸� �Ҵ�

	*pi = 100;		// �� ���� �޸� ���
	delete pi; 		// �� ���� �޸� �ݳ�

	return 0;
} 
