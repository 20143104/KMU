#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <ctime>

using namespace std;

int main(void)
{
	queue<int>  client;
	queue<int> ready;
	int totalready = 0, ave = 0, count = 0;
	int temp = 0;
	srand(time(NULL));

	cout<<"고객이 서비스 받는 시간 : ";
	for(int i = 0;i < 5; i++){
		temp = rand()%30+1;
		ready.push(temp);
		cout<<temp<<" ";
	}
	cout<<endl;
	cout<<"고객이 들어온 시간 : ";
	for(i = 0;i < 5; i++){
		temp = rand()%10+1;
		client.push(temp);
		cout<<temp<<" ";
	}
	cout<<endl;
	count = client.size();
	for(i = 0;i < 5; i++){
		totalready = totalready + ready.front() - client.front();
		ready.pop();
		client.pop();
	}
	ave = totalready/count;
	cout<<"고객의 평균 대기 시간 : "<<ave<<"분"<<endl;

	return 0;
}
