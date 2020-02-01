  #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
    #include "myheader.h"
   using namespace std;

	// ���ڿ��� ���̸� ������ �����Ѵ�.
   bool is_less (const string& s1, const string& s2)
   {
       return s1.length() < s2.length();
   }

   int main()
   {
       vector<string> vec1;
       vector<string> vec2;

       vec1.push_back ("AAAA");
       vec1.push_back ("AAAAAA");
       vec1.push_back ("BBBB");
       vec1.push_back ("AAA");
       vec1.push_back ("AA");
       vec1.push_back ("A");
       vec2 = vec1;

       print (vec1,"ó�� ���ڿ�\n");

       sort (vec1.begin(), vec1.end(), is_less);                             
       stable_sort (vec2.begin(), vec2.end(), is_less);                    

       print(vec1,"sort()���� ���ڿ�\n");
       print(vec2,"stable_sort()���� ���ڿ�\n");
	   return 0;
   }
