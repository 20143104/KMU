#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	
	if (argc != 2)
	{
		cout<<"잘못입력하셨습니다."<<endl;
		exit(1);
	}


	ifstream is;
	is.open(argv[1]);
	if(is.fail())
	{
		cerr << "파일 오픈 실패" <<endl;
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
	cout<<"문자수: "<<ch<<endl;
	cout<<"단어수: "<<word<<endl;
	cout<<"문장수: "<<line<<endl;

	is.close();
	return 0;
}