#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

using namespace std;

bool is_less(const string &s1, const string &s2)
{
	return s1.length() > s2.length();
}
bool is_size(string s)
{
	if(s.length() < 6)
		return true;
	else
		return false;

}

int main(void)
{
	vector<string> inputs;
	vector<string> temp;
	vector<string>::iterator tempiter;
	vector<string>::iterator tempiter2;
	vector<string>::iterator iter;
	string s;
	
	cout<<"������ �Է��Ͻÿ�."<<endl;
	while(1){
		cin>>s;
		inputs.push_back(s);
		if(cin.eof()){
			break;
		}
	}
	iter = inputs.begin();
	int i = 0;
	while(iter != inputs.end()){//�ߺ� ����
		tempiter = temp.begin();
		tempiter2 = find(temp.begin(),temp.end(),inputs[i]);
		if(tempiter2 == temp.end()){
			temp.push_back(*iter);
		}
		i++;
		iter++;
	}
	sort(temp.begin(),temp.end(),is_less);

	tempiter = temp.begin();
	while(tempiter != temp.end()){
		tempiter2 = find_if(temp.begin(),temp.end(),is_size);
		if(tempiter2 == temp.end()){
			
		}
		temp.erase(tempiter2, temp.end());
		tempiter++;
	}
	
	iter = temp.begin();
	cout<<"ũ�Ⱑ 6�̻��� �ܾ��� �� : "<<temp.size()<<endl;
	while(iter != temp.end()){
		cout<<*iter<<endl;
		iter++;
	}
	
	return 0;
}