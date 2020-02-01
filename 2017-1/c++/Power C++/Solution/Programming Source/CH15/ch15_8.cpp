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
	
	ifstream is, is1;
	is.open(argv[1]);
	if(is.fail())
	{
		cerr << "���� ���� ����1" <<endl;
		exit(1);
	}

	is1.open(argv[2]);
	if(is1.fail())
	{
		cerr << "���� ���� ����2" <<endl;
		exit(1);
	}
	
	
	char c,d;
	while(!is.eof())
	{
		is.get(c);
		is1.get(d);
		if(c != d){
			cout<<argv[1]<<"��"<<argv[2]<<"�� ��ġ ���� �ʽ��ϴ�.";
			is.close();
			is1.close();
			return 0;
		}
	}
	cout<<argv[1]<<"�� "<<argv[2]<<"�� ��ġ�մϴ�.";
	is.close();
	is1.close();
	return 0;
}
