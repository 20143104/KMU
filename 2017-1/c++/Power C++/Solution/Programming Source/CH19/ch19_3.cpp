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
	cout<<"난수의 최소 값 : "<<*iter<<endl;
	iter = num.end();
	cout<<"난수의 최대 값 : "<<*--iter<<endl;
	return 0;
}