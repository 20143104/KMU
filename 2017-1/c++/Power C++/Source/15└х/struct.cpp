#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	struct Score {
		int number;
		char name[30];
		int score;
	} grades[] = {	{20100001, "ȫ�浿", 100},
			{20100002, "������",  90},
			{20100003, "������",  80} };

	ofstream os;
	os.open("test.dat",ofstream::binary);
	if( os.fail() ) 
	{
		cout << "test.dat ������ �� �� �����ϴ�." << endl;
		exit(1);
	}
	os.write((char *)&grades, sizeof(grades));	
	os.close();
	return 0;
}
