#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string fruits[5] = { "���", "�丶��", "��", "����", "Ű��" };
	vector<string> vec(&fruits[0], &fruits[5]);	// �迭->����

	vector<string>::iterator it;		// �ݺ��� ����
	it = find(vec.begin(), vec.end(), "����");

	if (it != vec.end()) 	
		cout << "������ " << distance(vec.begin(), it) << "�� �ֽ��ϴ�." << endl;

	return 0;
}
