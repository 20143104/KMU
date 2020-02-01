#include <iostream>

using namespace std;

int main(void)
{
	int a = 1,b = 1,c = 1,count = 0;
	cout<<"a : b : c "<<endl;
	for(a = 1;a <= 100; a++){
		if(a*a == b*b + c*c){
			cout<<a<<" : "<<b<<" : "<<c<<endl;
			count++;
		}
		for(b = 1;b <= 100; b++){
			if(a*a == b*b + c*c){
				cout<<a<<" : "<<b<<" : "<<c<<endl;
				count++;
			}
			for(c = 1;c <= 100; c++){
				if(a*a == b*b + c*c){
					cout<<a<<" : "<<b<<" : "<<c<<endl;
					count++;
				}

			}
		}
	}
	cout<<"ÃÑ "<<count<<"°³"<<endl;
	
	
	return 0;
}
