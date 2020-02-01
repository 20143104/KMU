#include <iostream>

using namespace std;

int main(void)
{
	int table[3][5] = {{12,56,32,16,98},{99,56,34,41,3},{65,3,87,78,21}}, col[5] = {0}, row[3] = {0}, i, j;

	for(i = 0;i < 3; i++){
		
		for(j = 0;j < 5; j++){
			row[i] += table[i][j];
			col[j] += table[i][j];
		}
	}

	for(i = 0;i < 3; i++){
		cout<<i+1<<"번째 행의 합계 : "<<row[i]<<endl;
	}
	for(i = 0;i < 5; i++){
		cout<<i+1<<"번째 열의 합계 : "<<col[i]<<endl;
	}

	return 0;
}
