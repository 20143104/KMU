#include <iostream>
#include <ctime>

using namespace std;

int rand_range(int min, int max);

int main()
{
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, i, randnum = 0;
	srand(time(NULL));

	for(i = 0;i < 600; i++){
		randnum = rand_range(1,6);
		switch(randnum){
		case 1:
			one++;
			break;
		case 2:
			two++;
			break;
		case 3:
			three++;
			break;
		case 4:
			four++;
			break;
		case 5:
			five++;
			break;
		case 6:
			six++;
			break;
		default:
			break;
		}
	}

	cout<<"주사위 600번 던진 결과"<<endl;
	cout<<"1 : "<<one<<endl;
	cout<<"2 : "<<two<<endl;
	cout<<"3 : "<<three<<endl;
	cout<<"4 : "<<four<<endl;
	cout<<"5 : "<<five<<endl;
	cout<<"6 : "<<six<<endl;
	
	return 0;
}

int rand_range(int min, int max)
{
	
	return (rand()%(max+1) + min);

}