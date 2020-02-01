#include <iostream>
#include <ctime>

using namespace std;

void GetNum(int num)
{
	int i, chk_num=0, rnd = 0, lot = 0;
	int count_arr[10] = {0};

	for(i=0; i<num; i++){
		rnd = rand() % 9 + 1;
		switch(rnd){
		case 0:
			count_arr[0]++;
			break;
		case 1:
			count_arr[1]++;
			break;
		case 2:
			count_arr[2]++;
			break;
		case 3:
			count_arr[3]++;
			break;
		case 4:
			count_arr[4]++;
			break;
		case 5:
			count_arr[5]++;
			break;
		case 6:
			count_arr[6]++;
			break;
		case 7:
			count_arr[7]++;
			break;
		case 8:
			count_arr[8]++;
			break;
		case 9:
			count_arr[9]++;
			break;
		}
	}

	chk_num = count_arr[0];
	for(i=0 ; i< 9; i++)
	{
		if(chk_num < count_arr[i+1]){
			chk_num = count_arr[i+1];
			lot = i+1;
		}
	}

	cout<<"▶ 수 : "<<lot<<" 총 : "<<chk_num<<" 생성!"<<endl;
}

int main()
{
	srand(time(NULL));

	cout<<"0부터 9까지의 난수를 100번 생성하여 가장많이 생성된 수는 ?\n";
	GetNum(100);
	return 0;
}