#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool checkLeapyear(int y)
{
	if(y%4 == 0){
		if(y%100 == 0){
			if(y%400 != 0){
				return false;
			}
			return true;
		}
		return true;
	}
	else{
		return false;
	}
}

int main(void)
{
	vector<int> year(20);
	for(int i = 0;i < 20; i++){
		year[i] = 1990+i;
	}
	vector<int>::iterator iter = year.begin();
	while(1){
		iter = find_if(iter,year.end(),checkLeapyear);
		if(iter == year.end()){
			break;
		}
		else{
			cout<<"1990~2019년 사이의 첫 번째 윤년 : "<<*iter<<endl;
			return 0;
		}
		
	}
	return 0;
}
