// copy�� reverse�� ��� ��
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
   string names[5] = {"���","��","Ű��","����","����"}; 
   vector<string> fruits(5);
   vector<string>::iterator it;
   copy(&names[0], &names[5], fruits.begin());
   reverse(fruits.begin(), fruits.end());
   for (it = fruits.begin(); it != fruits.end(); ++it)
      cout << *it << " ";
   cout << endl;
}
