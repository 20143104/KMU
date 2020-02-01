#include <iostream>
#include <map>
#include <string>

using namespace std;

void Add(map<string,string> &dic, string s, string v);
void Search(map<string,string> dic, string s);
void Delete(map<string,string> &dic, string s);

int main(void)
{
	map<string,string> dictionary;
	string s,value;
	dictionary["boy"] = "소년";
	dictionary["school"] = "학교";
	dictionary["office"] = "직장";
	dictionary["house"] = "집";
	dictionary["morning"] = "아침";
	dictionary["evening"] = "저녘";
	int sel;
	while(1){
		cout<<"1. 단어 추가 2. 단어 검색 3. 단어 삭제 4. EXIT"<<endl;
		cout<<">>";
		cin>>sel;
		if(sel == 1){
			cout<<"단어 입력 : ";
			cin>>s;
			cout<<"뜻 입력 : ";
			cin>>value;
			Add(dictionary,s,value);
		}
		else if(sel == 2){
			cout<<"단어 입력 : ";
			cin>>s;
			Search(dictionary,s);
		}
		else if(sel == 3){
			cout<<"단어 입력 : ";
			cin>>s;
			Delete(dictionary,s);
		}	
		else if(sel == 4){
			return 0;
		}
	}
	return 0;
}

void Add(map<string,string> &dic, string s, string v)
{
	dic[s] = v;
}
void Search(map<string,string> dic, string s)
{
	if(!dic[s].empty()){
		cout<<s<<"의 의미는 "<<dic[s]<<endl;
	}
	else{
		cout<<"찾는 단어가 없습니다."<<endl;
	}
}
void Delete(map<string,string> &dic, string s)
{
	map<string,string>::iterator iter = dic.find(s);
	if(iter == dic.end()){
		cout<<"찾는 단어가 없습니다."<<endl;
	}
	else{
		dic.erase(iter);
	}
}