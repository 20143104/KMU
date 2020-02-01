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
	dictionary["boy"] = "�ҳ�";
	dictionary["school"] = "�б�";
	dictionary["office"] = "����";
	dictionary["house"] = "��";
	dictionary["morning"] = "��ħ";
	dictionary["evening"] = "����";
	int sel;
	while(1){
		cout<<"1. �ܾ� �߰� 2. �ܾ� �˻� 3. �ܾ� ���� 4. EXIT"<<endl;
		cout<<">>";
		cin>>sel;
		if(sel == 1){
			cout<<"�ܾ� �Է� : ";
			cin>>s;
			cout<<"�� �Է� : ";
			cin>>value;
			Add(dictionary,s,value);
		}
		else if(sel == 2){
			cout<<"�ܾ� �Է� : ";
			cin>>s;
			Search(dictionary,s);
		}
		else if(sel == 3){
			cout<<"�ܾ� �Է� : ";
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
		cout<<s<<"�� �ǹ̴� "<<dic[s]<<endl;
	}
	else{
		cout<<"ã�� �ܾ �����ϴ�."<<endl;
	}
}
void Delete(map<string,string> &dic, string s)
{
	map<string,string>::iterator iter = dic.find(s);
	if(iter == dic.end()){
		cout<<"ã�� �ܾ �����ϴ�."<<endl;
	}
	else{
		dic.erase(iter);
	}
}