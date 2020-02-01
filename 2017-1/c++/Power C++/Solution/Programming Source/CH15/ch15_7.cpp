#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	
	if (argc != 4)
	{
		cout<<"�߸��Է��ϼ̽��ϴ�."<<endl;
		exit(1);
	}
	
	ifstream is, is1;
	is.open(argv[1]);
	if(is.fail())
	{
		cerr << "���� ���� ����" <<endl;
		exit(1);
	}
	
	ofstream os;
	os.open(argv[3]);
	if(os.fail()){
		cerr << "���� ���� ����" <<endl;
		exit(1);
	}	
	char c;
	while(!is.eof())
	{
		is.get(c);
		os<<c;
	}
	is.close();

	is1.open(argv[2]);
	if(is1.fail())
	{
		cerr << "���� ���� ����" <<endl;
		exit(1);
	}
	
	while(!is1.eof())
	{
		is1.get(c);
		os<<c;
	}
	
	is1.close();
	
	cout<<argv[1]<<"�� "<<argv[2]<<"�� ���Ͽ� "<<argv[3]<<"�� �ۼ��Ͽ����ϴ�."<<endl;

	return 0;
}