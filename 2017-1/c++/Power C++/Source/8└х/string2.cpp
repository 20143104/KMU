#include <iostream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "This is a test."; // string ��ü�� �����ϰ� �ʱ�ȭ�Ѵ�. 
		
	s1.insert(4, "Hello");
	cout << s1 << endl;
	int index = s1.find("test");
	cout << index << endl;
	s1.append("World");
	cout << s1 << endl;
	return 0;
}
