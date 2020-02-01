#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout<<"�߸��Է��ϼ̽��ϴ�."<<endl;
		exit(1);
	}

	ifstream is;
	is.open(argv[1]);
	if(is.fail())
	{
		cerr << "���� ���� ����" <<endl;
		exit(1);
	}

	char c;
	int line_number = 1;
	is.get(c);
	cout<<line_number<<":    ";
	while(!is.eof())
	{
		cout<<c;
		if(c == '\n')
		{
			line_number++;
			cout<< line_number<<":    ";
		}
		is.get(c);
	}
	is.close();
	return 0;
}
