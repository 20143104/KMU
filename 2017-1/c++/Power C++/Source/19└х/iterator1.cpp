#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;		// ������ ���� ����	
	for(int i=0;i<10;i++)
		vec.push_back(i);

	vector<int>::iterator it;	// �ݺ��� ��ü ����
	for(it=vec.begin(); it != vec.end() ; it++)	// �����̳��� ��� ��Ҹ� ���
		cout << *it << " ";
	cout << endl;

	for(it=vec.begin(); it != vec.end() ; it++)	// �����̳��� ��� ��Ҹ� -1�� ����
		*it = 0;

	for(it=vec.begin(); it != vec.end() ; it++)	// �����̳��� ��� ��Ҹ� ���
		cout << *it << " ";
	cout << endl;
	return 0;
}
