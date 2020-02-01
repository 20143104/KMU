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

	cout<<"���� ���� �޴� �ð� : ";
	for(int i = 0;i < 5; i++){
		temp = rand()%30+1;
		ready.push(temp);
		cout<<temp<<" ";
	}
	cout<<endl;
	cout<<"���� ���� �ð� : ";
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
	cout<<"���� ��� ��� �ð� : "<<ave<<"��"<<endl;

	return 0;
}
