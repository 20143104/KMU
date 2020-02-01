#include <iostream>
#define MAX_SIZE 10

using std::ostream;
using std::istream;
using std::endl;
using std::cout;
using std::cin;


class Set
{
	friend ostream& operator<<(ostream& os, const Set& c);
	friend istream& operator>>(istream& os, const Set& c);

	int total;
	int elem[MAX_SIZE];
public:
	Set(){
		for(int i=0 ; i < MAX_SIZE; i++)
		{
			elem[i] = 0;
		}
		total = 0;
	}
    int operator+(int n)
	{
		if(total == MAX_SIZE)
			return -1;
		for(int i=0; i< MAX_SIZE; i++)
		{
			if(elem[i] == n)
			{
				cout<<"중복입니다."<<endl;
				return -1;
			}
		}
	
		for(i=0 ; i < MAX_SIZE; i++)
		{
			if(elem[i] == 0){
				elem[i] = n;
				total++;
				break;
			}
		}
		return 0;

	}
    void operator-(int n)
	{
		if(total == 0)
			exit(1);

		for(int i=0 ; i < MAX_SIZE; i++)
		{
			if(elem[i] == n){
				elem[i] = 0;
				total--;
				break;
			}
		}
	
	}
	Set operator|(const Set t)
	{
		Set temp;
		int k=0;
		for(int i=0; i < 10 ; i++)
		{
			if(this->elem[i] != 0){
				temp.elem[k] = this->elem[i];
				k++;
			}
		}
		for(i=0; i < 10 ; i++)
		{
			for(int j=0; j < 10 ; j++){
				if(temp.elem[i] == t.elem[j]){
			//		cout<<"1"<<endl;
					break;
				}
			}
		
			if(j >= 10 || temp.elem[i] == 0){
				temp.elem[k] = t.elem[i];
				k++;
			}	
		}
		return temp;
	}

	Set operator&(const Set t)
	{
		Set temp;
		int k=0;
		for(int i=0; i < 10 ; i++)
		{
			for(int j=0; j < 10 ; j++){
				if(this->elem[i] == t.elem[j]){
					temp.elem[k] = this->elem[i];
					k++;
					break;
				}
			}
		}
		return temp;
	}

	bool operator==(const Set t)
	{
		int tot = 0;
		if(this->total != t.total)
			return false;

		for(int i=0; i < this->total; i++)
		{
			for(int j=0; j < t.total; j++)
			{
				if(this->elem[i] == t.elem[j]){
					tot++;
					break;
				}
			}
		}
		if(tot == this->total)
			return true;
	}
	void display()
	{
		cout<<"{";
		for(int i=0; i < MAX_SIZE ; i++)
		{
			if(elem[i] == 0)
				break;
			else if(elem[i+1] == 0)
				cout<<elem[i];
			else{
				cout<<elem[i];
				cout<<",";
			}
		}
		cout<<"}"<<endl;
	}
};

ostream& operator<<(ostream& os, const Set& c)
{
	os<<"{";
	for(int i=0; i < MAX_SIZE ; i++)
	{
		if(c.elem[i] == 0)
			break;
		else if(c.elem[i+1] == 0)
			os<<c.elem[i];
		else{
			os<<c.elem[i];
			os<<",";
		}
	}
	os<<"}"<<endl;
	return os;
}

istream& operator>>(istream& is, const Set& c)
{
 	if(c.total >= MAX_SIZE)
 		return is;
	is>>(int)c.elem[c.total];
	return is;
}


int main()
{
	Set A, B, C;

	cout<<"집합 A의 원소는 : "<< endl;
	A+3;
	A.display();
	A+4;
	A.display();
	A+4;
	A.display();
	A-4;
	A.display();
	A+4;
	A.display();
	
	cout<<"집합 B의 원소는 : "<< endl;
	B+3;
	B.display();
	B+4;
	B.display();
 	B+5;
	B.display();
	
	cout<<"집합 A와 B의 합집합 : "<< endl;

	C = A|B;
	C.display();
	
	cout<<"집합 A와 B의 교집합 : "<< endl;
	C = A&B;
	C.display();
	
	cout<<"집합 A와 B의 ==연산자 : "<< endl;
	bool tmp = A==B;
	if(tmp == true)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	
	cout<<"집합 A의 <<연산자 : "<< endl;
	cout<<A;
	cout<<"집합 A의 >>연산자 : "<< endl;
	cin>>A;
	A.display();

	return 0;
}
