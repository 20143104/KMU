#include <iostream>

using namespace std;

int main()
{
	int i,j;
	int ttt[3][3]={0};

	for(i=0 ; i < 3; i++){
		for(j=0 ; j < 3; j++){
			cout<<"배열에 값을 입력하세요"<<"["<<i<<","<<j<<"] : ";
			cin>>ttt[i][j];
		}
	}

	for(i=0 ; i < 3; i++){
		for(j=0 ; j < 3; j++){
			if( ttt[i][j] == 0){
				cout<<"■"<<"\t";
			}
			else if( ttt[i][j] == 1){
				cout<<"○"<<"\t";
			}
			else if( ttt[i][j] == 2){
				cout<<"×"<<"\t";
			}
		}
		cout<<endl;
	}
}
