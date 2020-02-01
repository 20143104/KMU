#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	char line[100];
	char input[100];

	if (argc != 3)
	{
		cout<<"잘못입력하셨습니다."<<endl;
		exit(1);
	}

	strcpy(input, argv[2]);

	ifstream is;
	is.open(argv[1]);

	for(int count=0; count < 100 ; count++)
	{
		if( input[count] == NULL)
			break;
	}

	int line_number=1;

	while(!is.eof())
	{
		char temp[200];
		is.getline(temp,200,'\n');
		for(int i=0; i < 200; i++)
		{
			if(temp[i] == input[0])
			{
				for(int j=0; j<count; j++){
					if(temp[i+j] != input[j])
						break;
				}
				if(j == count){
					cout<<argv[1]<<":"<<line_number<<"  "<<temp<<endl;
					break;
				}
			}
		}
		line_number++;
		for(i=0 ; i< 200; i++)
			temp[i] = ' '; //변수 초기화
	}
	
	is.close();
	return 0;
}
