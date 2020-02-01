#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	vector<int> vec;
	for(int i=0;i<10;++i) 		// vec = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
		vec.push_back(i);

	list<int> ilist;
	for(int i=3;i<6;++i) 		// ilist = (3, 4, 5)
		ilist.push_back(i);

	vector<int>::iterator it;
	it = search(vec.begin(),vec.end(), ilist.begin(), ilist.end());	

	if (it != vec.end()){ 	
		cout << "�κ� ������ " << distance(vec.begin(), it) << "�� �ֽ��ϴ�." << endl;
	}

	return 0;
}
