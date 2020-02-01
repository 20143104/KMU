#include <iostream>
#define MAXSIZE 10

using namespace std;

template<typename T>
class Set{
private:
	T data[MAXSIZE];
	int count;
public:
	Set()
	{
		count = 0;
	}
	void Add(T d)
	{
		if(count < MAXSIZE){
		if(checkData(d)){
			data[count] = d;
			count++;
		}
		else{ 
			cout<<"동일값 입력"<<endl;
		}
		}
		else{
			cout<<"입력 범위 초과"<<endl;
		}
	}
	bool checkData(T d)
	{
		for(int i = 0;i < count; i++){
			if(data[i] == d){
				return false;
			}
		}
		return true;
	}
	void print()
	{
		cout<<"Set = [ ";
		for(int i = 0;i < count; i++){
			cout<<data[i]<<" ";
		}
		cout<<"]"<<endl;
	}
	
};

int main(void)
{
	Set<int> s;
	int sel, data;
	while(1){
		cout<<"1. ADD  2.PRINT  3.EXIT"<<endl;
		cin>>sel;
		try{
			if(sel == 1){
				cout<<"Input Data : ";
				cin>>data;
				s.Add(data);
			}
			else if(sel == 2){
				s.print();
			}
			else if(sel == 3){
				return 0;
			}
			else 
				throw sel;
		}
		catch(int sel){
			cout<<"입력 범위 초과"<<endl;
		}
	}
	return 0;	
}