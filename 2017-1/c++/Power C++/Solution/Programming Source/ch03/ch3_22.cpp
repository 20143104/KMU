#include <iostream>

using namespace std;

int main()
{
	int i;
	double re = 1;
	
	for(i=1; i <= 100; i++){
		if(i%2 == 1){
			re = re * i;
		}
	}
	cout<<"1ºÎÅÍ 100±îÁöÀÇ È¦¼öÀÇ °ö : "<<re<<endl;
	return 0;	
}
