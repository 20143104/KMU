#include <iostream>
using namespace std;

int main() 
{ 
	int var;
	int &ref = var; 		// ���۷��� ���� 

	var = 10;		
	cout << "var�� ��: " << var << endl;
	cout << "ref�� ��: " << ref << endl;

	ref = 20;		// ref�� ���� �����ϸ� var�� ���� ����ȴ�. 
	cout << "var�� ��: " << var << endl;
	cout << "ref�� ��: " << ref << endl;

	return 0;
}
