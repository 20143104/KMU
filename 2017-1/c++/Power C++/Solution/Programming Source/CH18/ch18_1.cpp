#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<double> score(10);
	double s = 0, min = 0, max = 0, final = 0;
	for(int i = 0;i < 10; i++){
		cout<<"������ �Է��Ͻÿ�. : ";
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
	cout<<"�������� : "<<final<<endl;

	return 0;
}