#include <iostream>
#include <string>
using namespace std;

class ParentClass {
public:
    void print() {
        cout << "�θ� Ŭ������ print() ��� �Լ�" << endl;
    }
};

class ChildClass : public ParentClass {
 	int data;
public:
    void print() { //��� �Լ� �������̵� 
        ParentClass::print();
        cout << "�ڽ� Ŭ������ print() ��� �Լ� " << endl;
    }
};
int main()
{
    ChildClass obj;
    obj.print();     
	return 0;
}
