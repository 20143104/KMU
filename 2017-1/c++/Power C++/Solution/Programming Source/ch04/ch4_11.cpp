#include <iostream>

using namespace std;

int result;

void menu();
void addition(int x, int y);
void multiply(int x, int y);
void subtraction(int x, int y);
void division(int x, int y);


int main(void)
{
	menu();

	return 0;
}
void menu()
{
	int x = 0, y = 0;
	char cal, q;
	
	
	cout<<"������ �Է��Ͻÿ�: ";
	cin>>x>>cal>>y;
	
	switch(cal){
	case '+':
		addition(x,y);
		break;
	case '-':
		subtraction(x,y);
		break;
	case '*':
		multiply(x,y);
		break;
	case '/':
		division(x,y);
		break;
	default:
		menu();
		break;
	}
	menu();
	

}

void addition(int x, int y)
{
	static int add = 0;
	result = x + y;
	cout<<"���� ���: "<<result<<endl;
	add++;
	cout<<"������ �� "<<add<<"�� ����Ǿ����ϴ�."<<endl;
}
void multiply(int x, int y)
{
	static int multi = 0;
	result = x * y;
	cout<<"���� ���: "<<result<<endl;
	multi++;
	cout<<"������ �� "<<multi<<"�� ����Ǿ����ϴ�."<<endl;
}
void subtraction(int x, int y)
{
	static int sub = 0;
	result = x - y;
	cout<<"���� ���: "<<result<<endl;
	sub++;
	cout<<"������ �� "<<sub<<"�� ����Ǿ����ϴ�."<<endl;
}
void division(int x, int y)
{
	static int divi = 0;
	result = x / y;
	cout<<"���� ���: "<<result<<endl;
	divi++;
	cout<<"�������� �� "<<divi<<"�� ����Ǿ����ϴ�."<<endl;
}