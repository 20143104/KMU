#include <iostream>
#include <cmath>

using namespace std;

void average(double number[]);
void standard(double number[],double ave);

int main(void)
{
	double number[20];
	int i;

	cout<<"�Ǽ� 20���� �Է��Ͻÿ�"<<endl;
	for(i = 0;i < 20; i++){
		cout<<">>";
		cin>>number[i];
	}
	average(number);
	return 0;
}

void average(double number[])
{
	int i;
	double ave = 0;

	for(i = 0;i < 20; i++){
		ave += number[i];
	}
	ave = ave/20;
	cout<<"����� "<<ave<<endl;
	standard(number, ave);
}
void standard(double number[], double ave)
{
	int i;
	double stand = 0;

	for(i = 0;i < 20; i++){
		stand += pow((number[i] - ave),2);
	
	}
	stand = sqrt(stand/20);
	cout<<"ǥ�������� "<<stand<<endl;
}