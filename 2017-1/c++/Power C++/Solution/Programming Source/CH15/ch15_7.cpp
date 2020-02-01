#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	
	if (argc != 4)
	{
		cout<<"잘못입력하셨습니다."<<endl;
		exit(1);
	}
	
	ifstream is, is1;
	is.open(argv[1]);
	if(is.fail())
	{
		cerr << "파일 오픈 실패" <<endl;
		exit(1);
	}
	
	ofstream os;
	os.open(argv[3]);
	if(os.fail()){
		cerr << "파일 오픈 실패" <<endl;
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
		cerr << "파일 오픈 실패" <<endl;
		exit(1);
	}
	
	while(!is1.eof())
	{
		is1.get(c);
		os<<c;
	}
	
	is1.close();
	
	cout<<argv[1]<<"와 "<<argv[2]<<"를 합하여 "<<argv[3]<<"를 작성하였습니다."<<endl;

	return 0;
}