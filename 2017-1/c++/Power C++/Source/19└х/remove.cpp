#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "myheader.h"
using namespace std;

int main()
{
	string names[5] = {"���","��","Ű��","����","����"}; 
	vector<string> fruits(5);
	copy(&names[0], &names[5], fruits.begin());
	print(fruits, "������\n");
	vector<string>::iterator it;
	it = remove(fruits.begin(), fruits.end(), "����");
	print(fruits, "remove() ��\n");
	fruits.erase(it, fruits.end());
	print(fruits, "erase() ��\n");
	return 0;
}
