#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;		// ������ ���� ����	
	for(int i=0;i<10;i++)
		vec.push_back(i);
	vector<int>::reverse_iterator rit;		// ������ ���� ����	
	for(rit = vec.rbegin(); rit!= vec.rend() ; rit++)
		cout << *rit << " ";
	cout << endl;
	return 0;
}
