#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> table;
	string s;

	cout << "������ �Է��Ͻÿ�(����� Ctrl-Z): ";
	while(1){
		cin >> s;
		table[s]++;
		if( cin.eof() ) break;
	}
	
	map<string, int>::iterator iter;
	for (iter=table.begin();iter!=table.end();iter++) {
		cout << iter->first << " : " << iter->second << endl;
	}
	return 0;
}
