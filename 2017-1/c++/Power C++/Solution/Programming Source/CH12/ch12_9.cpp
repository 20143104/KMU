#include <iostream>
#include <string>

using namespace std;

class SymbolTable{
private:
	string key[10];
	int value[10];
	int total;
public:
	SymbolTable(){
		for(int i=0; i< 10 ; i++){
			key[i]="";
			value[i] = 0;
			total = 0;
		}
	}
	void add(string key, int value)
	{
		for(int i=0; i< 10 ; i++){
			if(this->value[i] == 0){
				this->key[i] = key;
				this->value[i] = value;
				total++;
				break;
			}
		}		
	}
	void del(string key){
		for(int i=0; i< 10; i++){
			if( this->key[i] == key){
				this->key[i]="";
				this->value[i] = 0;
				total--;
				break;
			}
		}
	}
	int operator[](string key){
		for(int i=0; i < 10; i++){
			if( this->key[i] == key){
				return this->value[i];
			}
		}
		return -1;
	}
};

int main()
{
	SymbolTable table;
	table.add("house", 100);
	table.add("mouse", 200);
	table.add("korea", 300);
	table.del("mouse");
	cout<< table["house"] << endl;
	return 0;	
}