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

	int number;		//�й�
	char name[30];	// �̸�
	int score;		// ����
	is >> number >> name >> score;

	ofstream os;
	os.open("result.txt");
	os << number << " " << name << " " << score << endl;

	is.close();
	os.close();
	return 0;
}			
