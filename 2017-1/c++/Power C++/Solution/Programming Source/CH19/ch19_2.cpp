#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

bool checkEven(int n)
{
	if(n%2 == 0){
		return true;
	}
	else{
	return false;
	}
}

int main(void)
{
	srand(time(NULL));
	vector<int> num;
	for(int i = 0;i < 100; i++){
		num.push_back(rand());
	}
	size_t count = count_if(num.begin(),num.end(),checkEven);
	cout<<"벡터 내의 난수의 짝수의 개수 : "<<count<<endl;
	return 0;
}
