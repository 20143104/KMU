#include <iostream>
#include <string>
using namespace std;

class Company {
private:
	int sales, profit;
	// sub()�� Company�� ���� �κп� ������ �� �ִ�. 
	friend void sub(Company& c);
public:
	Company(): sales(0), profit(0)
	{
	}
};
void sub(Company& c)
{
	cout << c.profit << endl;
}
int main()
{
	Company c1;
	sub(c1);
	return 0;
}
