#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout<<"�߸��Է��ϼ̽��ϴ�."<<endl;
		exit(1);
	}

	ifstream is;
	is.open(argv[1]);
	ofstream os;
	os.open(argv[2]);
	char c;
	char tmp;
	while(!is.eof())
	{
		is.get(c);
		if ( c !=' ')
			tmp = c-29;
		else 
			tmp = c;
		os << tmp;
	}
	cout<<"���� ��ȣ�� ��ȣȭ�Ͽ����ϴ�."<<endl;
	is.close();
	os.close();
	return 0;
}
