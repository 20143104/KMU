#include <iostream>
#include <set>
#include <ctime>

using namespace std;

int main(void)
{
	set<int> lotto;
	set<int>::iterator iter;
	int lnum = 0;
	srand(time(NULL));

	for(int i = 0;i < 6; i++){
		lnum = (rand()%45)+1;
		lotto.insert(lnum);
		
		//cout<<*iter<<endl;
	}
	while(lotto.size()!=6){
		lnum = (rand()%45)+1;
		lotto.insert(lnum);
	}

	cout<<"로또 번호 발생기"<<endl;
	cout<<"로또 번호 : ";
	iter = lotto.begin();
	while(iter != lotto.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
	return 0;
}
