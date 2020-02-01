#include <iostream>
#include <vector>

using namespace std;

void Decimal(vector<int> &l);
void print(vector<int> l);

int main(void)
{
	vector<int> v(101);
	for(int i = 0;i <= 100; i++){
		v[i] = 0;
	}
	Decimal(v);
	print(v);
	return 0;
}
void Decimal(vector<int> &v)
{	
	int i,j,k;
	for(i=2;i<=100;i++){
		if(v[i]==0){
			k=0;
			for(j=2;j<i;j++){
				if(i%j==0){
					k++;
				}
			}
			if(k!=0){
				for(k=1;k*i<=100;k++){
					v[k*i]=1;
				}
			}
		}
	}

}
void print(vector<int> v)
{

	for(int i = 2;i <= 100;i++){
		if(v[i] == 0){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}