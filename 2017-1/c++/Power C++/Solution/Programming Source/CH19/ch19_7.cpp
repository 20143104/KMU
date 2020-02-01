#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	vector<string> chulsu;
	vector<string> younghee;
	vector<string> invite(10);

	chulsu.push_back("CSK");
	chulsu.push_back("BHJ");
	chulsu.push_back("RDJ");
	
	younghee.push_back("CSK");
	younghee.push_back("LYD");
	younghee.push_back("BHJ");
	younghee.push_back("SJW");

	sort(chulsu.begin(),chulsu.end(), less<string>());
	sort(younghee.begin(),younghee.end(), less<string>());

	cout<<"Ã¶¼ö Ä£±¸ : ";
	for(int i=0; i< chulsu.size(); i++)
		cout<< chulsu[i] <<" ";
	cout<<endl;

	cout<<"¿µÈñ Ä£±¸ : ";
	for(int j=0; j < younghee.size(); j++)
		cout<< younghee[j] <<" ";
	cout<<endl;

	copy(chulsu.begin(), chulsu.end(), invite.begin());
	copy(younghee.begin(), younghee.end(), invite.begin()+i);

	cout<<"Ã¶Èñ¿Í ¿µ¼öÄ£±¸ ÇÕ : ";
	for(j=0; j < invite.size(); j++)
		cout<< invite[j] <<" ";
	cout<<endl;

	vector<string>::iterator it;
	
	for(j=0; j < invite.size(); j++)
	{
		int n = count(invite.begin(),invite.end(), invite[j]);
		if(n >= 2)
		{
			it = remove(invite.begin(), invite.end(), invite[j]);
			invite.erase(it, invite.end());
 		}
	}
	sort(invite.begin(), invite.end(), less<string>());
	cout<<"Ã¶Èñ¿Í ¿µ¼öÄ£±¸ ÇÕ(Áßº¹Á¦°Å): ";
	for(j=0; j < invite.size(); j++)
		cout<< invite[j] <<" ";
	cout<<endl;

	return 0;
}
