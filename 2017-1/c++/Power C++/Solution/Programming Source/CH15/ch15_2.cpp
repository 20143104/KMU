#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout<<"잘못입력하셨습니다."<<endl;
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
	cout<<"시저 암호로 암호화하였습니다."<<endl;
	is.close();
	os.close();
	return 0;
}
