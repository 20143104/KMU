#include <iostream>

using namespace std;

#define MAX_SIZE 5

int main(void)
{
	int table[MAX_SIZE][MAX_SIZE] = {0}, col[MAX_SIZE] = {0}, row[MAX_SIZE] = {0}, i, j;

	cout<<"데이터를 입력하시오(11 42 23 24 33)"<<endl;
	for(i = 0;i < MAX_SIZE; i++){
		cin>>table[i][0]>>table[i][1]>>table[i][2]>>table[i][3]>>table[i][4];
	}
	
	for(i = 0;i < MAX_SIZE; i++){
		for(j = 0;j < MAX_SIZE; j++){
			row[i] += table[i][j];
			col[j] += table[i][j];
			cout<<table[i][j]<<"\t";
		}
		cout<<row[i]<<endl;
	}

	for(i = 0;i < MAX_SIZE; i++){
		cout<<col[i]<<"\t";
	}
	cout<<endl;
	return 0;
}
