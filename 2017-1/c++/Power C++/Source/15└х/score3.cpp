#include <iostream>
#include <fstream>		// ���� ������� �Ϸ��� ��� ������ �����Ͽ��� �Ѵ�. 
using namespace std;

int main()
{
	ofstream os;
	char c;
	os.open("test.txt");
	while( cin.get(c)  )
	{	
		os.put(c);
	}
	os.close();
	return 0;
}
