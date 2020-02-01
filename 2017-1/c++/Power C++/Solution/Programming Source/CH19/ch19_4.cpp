#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

vector<int> vectorAdd(vector<int> a, vector<int> b)
{
	vector<int> c;
	for(int i = 0;i < 10;i++){
		c.push_back(a[i] + b[i]);
	}
	return c;
}

int main(void)
{
	vector<int> a(10);
	vector<int> b(10);
	vector<int> c(10);
	cout<<"บคลอ A [ ";
	for(int i = 0;i < 10; i++){
		a[i] = i+1;
		cout<<a[i]<<" ";
	}
	cout<<"]"<<endl;
	cout<<"บคลอ B [ ";
	for(i = 0;i < 10; i++){
		b[i] = i+10;
		cout<<b[i]<<" ";
	}
	cout<<"]"<<endl;
	cout<<"บคลอ C [ ";
	
	transform(a.begin(),a.end(),b.begin(),c.begin(),plus<int>());
	for(i = 0;i < 10; i++){
		cout<<c[i]<<" ";
	}
	cout<<"]"<<endl;
	return 0;
}
