#include <iostream>
using namespace std;

class SuperA 
{   
public: 
	int x;
	void sub(){
		cout << "SuperA�� sub()" << endl;
	}   
};
class SuperB
{   
public: 
	int x;   
	void sub(){
		cout << "SuperB�� sub()" << endl;
	}   
};
class Sub : public  SuperA, public SuperB	
{
};

int main()
{
	Sub obj;
	obj.x = 10; 		// obj.x�� � �θ� Ŭ������ x�� �����ϴ°�?
	return 0;
}
