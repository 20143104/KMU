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
	
	ifstream is, is1;
	is.open(argv[1]);
	if(is.fail())
	{
		cerr << "파일 오픈 실패1" <<endl;
		exit(1);
	}

	is1.open(argv[2]);
	if(is1.fail())
	{
		cerr << "파일 오픈 실패2" <<endl;
		exit(1);
	}
	
	
	char c,d;
	while(!is.eof())
	{
		is.get(c);
		is1.get(d);
		if(c != d){
			cout<<argv[1]<<"와"<<argv[2]<<"는 일치 하지 않습니다.";
			is.close();
			is1.close();
			return 0;
		}
	}
	cout<<argv[1]<<"와 "<<argv[2]<<"는 일치합니다.";
	is.close();
	is1.close();
	return 0;
}
