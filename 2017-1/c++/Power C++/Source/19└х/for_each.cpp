#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// �� ��ҿ� ���Ͽ� ȣ��Ǵ� �Լ�
void display(int element)
{
	cout << element << ' ';
}
int main()
{
	vector<int> vec;
	for(int i=0;i<10; i++)
		vec.push_back(i);

	for_each (vec.begin(), vec.end(),  display);
	cout << endl;
	return 0;
}
