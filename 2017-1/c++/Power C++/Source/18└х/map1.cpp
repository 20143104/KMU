#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
     map<string, string> dic;
     dic["boy"]="�ҳ�";
     dic["school"]="�б�";
     dic["office"]="����";
     dic["house"]="��";
     dic["morning"]="��ħ";
     dic["evening"]="����";

     cout << "house�� �ǹ̴� " << dic["house"] << endl;	// ����� �� �ܾ�
     cout << "morning�� �ǹ̴� " << dic["morning"] << endl;	// ����� �� �ܾ�
     cout << "unknown�� �ǹ̴� " << dic["unknown"] << endl;	// ����� �ȵ� �ܾ�
	 return 0;
}
