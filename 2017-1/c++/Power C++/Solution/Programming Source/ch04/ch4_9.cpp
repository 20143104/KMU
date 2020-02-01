#include <iostream>
#include <ctime>

using namespace std;

int RandCoin(void);

int main()
{
	int win = 0, lose = 0, user = 0;
	srand(time(NULL));

	while(1){
		cout<<"사용자 (앞 = 1, 뒤 = 0, END = 9) : ";
		cin>>user;
		if(user == 9){
			break;
		}
		if(RandCoin() == user){
			win++;
		}
		else{
			lose++;
		}
		cout<<"WIN : "<<win<<" , LOSE : "<<lose<<endl;

	}


	return 0;
}

int RandCoin(void)
{
	if(rand()%2 == 0){
		return 1;
	}
	else{
		return 0;
	}
}