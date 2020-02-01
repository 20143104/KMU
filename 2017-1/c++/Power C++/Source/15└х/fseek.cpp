#include <iostream>
#include <fstream>
using namespace std;

const int SIZE=1000;
void init_table(int table[], int size);

int main()
{
	int table[SIZE];
	int data;
	long pos;
	
	// �迭�� �ʱ�ȭ�Ѵ�.
	init_table(table, SIZE);

	// ���� ������ ���� ���� ����.
	ofstream os;
	os.open("test.dat",ofstream::binary);
	if( os.fail() ) 
	{
		cout << "test.dat ������ �� �� �����ϴ�." << endl;
		exit(1);
	}

	// �迭�� ���� ���� ���Ͽ� �����Ѵ�.
	os.write((char *)table, sizeof(table));
	os.close();

	// ���� ������ �б� ���� ����.
	ifstream is;
	is.open("test.dat",ofstream::binary);
	if( is.fail() ) 
	{
		cout << "test.dat ������ �� �� �����ϴ�." << endl;
		exit(1);
	}

	// ����ڰ� ������ ��ġ�� ������ ���Ϸκ��� �д´�.
	while(1)
	{	
		cout <<"���Ͽ����� ��ġ�� �Է��Ͻʽÿ�(0���� 999, ����-1): ";
		cin >> pos;
		if( pos == -1 ) break;
		is.seekg(pos*sizeof(int), ios::beg);
		is.read((char *)&data, sizeof(int));
		cout << pos << " ��ġ�� ����" << data << " �Դϴ�." << endl;
	}
	is.close();
	return 0;
} 
	
// �迭�� �ε����� �������� ä���.
void init_table(int table[], int size)
{
	int i;

	for(i = 0; i < size; i++)
		table[i] = i * i;
}
