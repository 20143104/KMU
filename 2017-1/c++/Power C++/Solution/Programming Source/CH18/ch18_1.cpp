#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<double> score(10);
	double s = 0, min = 0, max = 0, final = 0;
	for(int i = 0;i < 10; i++){
		cout<<"점수를 입력하시오. : ";
		cin>>s;
		score[i] = s;
	}
	min = score[0];
	for(i = 0;i < 10; i++){
		if(min > score[i]){
			min = score[i];
		}
		if(max < score[i]){
			max = score[i];
		}
		final = final + score[i];
	}
	final = final - min - max;
	cout<<"최종점수 : "<<final<<endl;

	return 0;
}