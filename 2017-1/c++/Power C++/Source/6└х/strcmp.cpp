// strcmp() �Լ�
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s1[80];	// ù��° �ܾ ������ ���ڹ迭
	char s2[80];	// �ι�° �ܾ ������ ���ڹ迭
	int result;

	cout << "ù��° �ܾ �Է��Ͻÿ�:";
	cin >> s1;
	cout << "�ι�° �ܾ �Է��Ͻÿ�:";
	cin >> s2;

	result = strcmp(s1, s2);
	if( result < 0 )
		cout << s1 << "�� " << s2 << "���� �տ� �ֽ��ϴ�." << endl;
	else if( result == 0 )
		cout << s1 << "�� " << s2 << "�� �����ϴ�." << endl;
	else 
		cout << s1 << "�� " << s2 << "���� �ڿ� �ֽ��ϴ�." << endl;
	return 0;
}
