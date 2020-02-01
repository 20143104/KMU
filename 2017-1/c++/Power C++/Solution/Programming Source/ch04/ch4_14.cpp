#include <iostream>

using namespace std;
int addition(int x);

int main()
{
	int x = 0;
	cout<<"ют╥б: ";
	cin>>x;
	cout<<addition(x)<<endl;
	return 0;
}
int addition(int x)
{
	if(x == 1){
		return 1;
	}
	else{
		return(x*x*x + addition(x-1));
	}

}