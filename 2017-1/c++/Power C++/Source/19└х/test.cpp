#include <iostream>
#include <vector>
#include "myheader.h"
using namespace std;

int main()
{
	vector<int> vec;	// ������ ���� ����	

	vec.push_back(10);	// ������ ���� ������ �߰�
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	print(vec);		// ������ ��� ��Ҹ� ����Ѵ�.
	return 0;
}
