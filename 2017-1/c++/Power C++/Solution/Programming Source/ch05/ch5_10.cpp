#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int arr[6][4]={0};
	int i,j;

	srand((int)time(NULL));

	for(i=0; i<6; i++){
		for(j=0; j<4; j++){
			arr[i][j] = rand()%9+1;
		}
	}

	for(i=0; i<6; i++){
		for(j=0; j<4; j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
	return 0;
}
