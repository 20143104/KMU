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
	int ch=0;
	int word=0;
	int line=0;

	char temp[200];
	char *ptr;
	while(!is.eof())
	{
		is.getline(temp,200,'\n');
		ptr = temp;
		for(int i=0; i < 200; i++)
		{
			if(temp[i] != ' ' && (temp[i+1] == ' ' || temp[i+1] == NULL))
				word++;
			if(temp[i] == NULL)
				break;
			if(temp[i] != ' ')
				ch++;
		}
		line++;
	}
	cout<<"���ڼ�: "<<ch<<endl;
	cout<<"�ܾ��: "<<word<<endl;
	cout<<"�����: "<<line<<endl;

	is.close();
	return 0;
}