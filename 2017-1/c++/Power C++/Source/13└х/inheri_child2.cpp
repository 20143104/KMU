#include <iostream>
using namespace std;

class ParentClass {
public:
	const static int x=100;	// ���� ��� ���Ǵ� �ʱ�ȭ�� �����ϴ�.
};

class ChildClass1 : public ParentClass {
};
class ChildClass2 : private ParentClass {
};

int main()
{
    ChildClass1 obj1;
    ChildClass2 obj2;
    cout << obj1.x << endl;     	// ����: x�� public���� �����ȴ�.
    cout << obj2.x << endl;     	// ����!!! �Ұ���: x�� public���� private�� ����Ǿ���.
	return 0;
}
