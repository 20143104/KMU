#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;		// ������ ���� ����	
	for(int i=0;i<10;i++)
		vec.push_back(i);

	vector<int>::iterator it;	// �ݺ��� ��ü ����
	it = vec.begin();
	cout << it[2] << " " << endl;
	cout << *(it+2) << " " << endl;
	it = it + 5;
	it--;
	cout << *it << " " << endl;
	return 0;
}
