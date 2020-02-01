#include <iostream>

using namespace std;


class NotFound
{
public:
	void display(){	cout<<"NotFound"<<endl;	}
	
};

class SearchArray
{
	int index;
	int *ptr;
public:
	SearchArray(int *p, int i)
	{
		ptr = p;
		index = i;
	}
	void searchNum(int num)
	{
		int *tmp = ptr;
		
		for(int i=0; i< index ; i++){
			if(*tmp == num)
			{
				cout<<num<<"은 배열안에 존재합니다."<<endl;
				break;
			}	
			tmp++;
		}
		if(i == index) throw NotFound();
	}
	void display()
	{
		int *p = ptr;
		cout<<"배열에 저장된 값은... " <<endl;
		for(int i=0; i< index ; i++)
		{
			cout<<"["<<*p<<"] ";
			
			p++;
		}
		cout<<endl;
	}
};

int main()
{
	int input=0;
	int s[10]={11,22,33,44,55,66,77,88,99,111};
	SearchArray sa(s, 10);
	try{
		sa.display();
		cout<<"찾을 값을 입력하세요 : ";
		cin>>input;
		sa.searchNum(input);
	}
	catch (NotFound& e) 
	{
		e.display();
	}
	return 0;
}