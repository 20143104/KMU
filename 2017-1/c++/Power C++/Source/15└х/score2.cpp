#include <iostream>
#include <fstream>		// ���� ������� �Ϸ��� ��� ������ �����Ͽ��� �Ѵ�. 
using namespace std;

int main()
{
	ifstream is;
	is.open("score.txt");
	if( !is ) {		// ! ������ �����ε�
		cerr << "���� ���¿� �����Ͽ����ϴ�" << endl;
		exit( 1 );
	}
	char c;
	is.get(c);		// �ϳ��� ���ڸ� �д´�.
	while(! is.eof() )
	{
		cout << c;
		is.get(c);
	}
	is.close();
	return 0;
}
