#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;


int main(void)
{
	srand(time(NULL));
	vector<int> num;
	vector<int>::iterator iter;
	for(int i = 0;i < 100; i++){
		num.push_back(rand());
	}
	sort(num.begin(),num.end());
	iter = num.begin();
	cout<<"������ �ּ� �� : "<<*iter<<endl;
	iter = num.end();
	cout<<"������ �ִ� �� : "<<*--iter<<endl;
	return 0;
}