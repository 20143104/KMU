#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> vec;		// ���͸� �����Ѵ�. 

	vec.push_back("MILK");		// ������ ���� �ڷḦ �����Ѵ�.
	vec.push_back("BREAD");
	vec.push_back("BUTTER");

	vector<string>::iterator it;	// ���͸� ��ȸ�ϱ� ���ؿ� �ݺ��ڸ� �����Ѵ�.
	for(int i=0;i<vec.size();i++)
		cout << vec[i] << " ";	// [] ������ ���
	cout << endl;

	vec.insert(vec.begin()+1, "APPLE");	// ������ ù�κп� �ڷḦ �����Ѵ�.
	vec.pop_back();		// ������ ������ �ڷḦ �����Ѵ�.

	for (it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}
