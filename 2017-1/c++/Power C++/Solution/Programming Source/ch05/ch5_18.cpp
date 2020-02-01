#include <iostream>

using namespace std;

int main(void)
{
	int seatnum[10][8] = {{0},{0},{0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}}, i,j, count = 0;

	while(1){
		count = 0;
		for(i = 0;i < 10; i++){
			for(j = 0;j < 8; j++){
				cout<<seatnum[i][j]<<"  ";
				if(seatnum[i][j] == 1){
					count++;
				}
			}
			cout<<endl;
		}
		cout<<endl;
		if(count >= (i*j)){
			cout<<"모든 좌석이 예약되었습니다."<<endl;
			break;
		}
		cout<<"예약할 좌석의 번호를 입력하시오((1~10) (1~8))(종료 -1): ";
		cin>>i>>j;
		if(i == -1 || j == -1){
			break;
		}
		i = i - 1;
		j = j - 1;
		if(seatnum[i][j] == 1){
			cout<<endl;
			cout<<"이미 예약된 좌석입니다."<<endl;
			cout<<endl;
		}
		else{
			seatnum[i][j] = 1;
		}

	}

	return 0;
}