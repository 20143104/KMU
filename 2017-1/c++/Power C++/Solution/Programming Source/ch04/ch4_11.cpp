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
	
	
	cout<<"연산을 입력하시오: ";
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
	cout<<"연산 결과: "<<result<<endl;
	add++;
	cout<<"덧셈은 총 "<<add<<"번 실행되었습니다."<<endl;
}
void multiply(int x, int y)
{
	static int multi = 0;
	result = x * y;
	cout<<"연산 결과: "<<result<<endl;
	multi++;
	cout<<"곱셈은 총 "<<multi<<"번 실행되었습니다."<<endl;
}
void subtraction(int x, int y)
{
	static int sub = 0;
	result = x - y;
	cout<<"연산 결과: "<<result<<endl;
	sub++;
	cout<<"뺄셈은 총 "<<sub<<"번 실행되었습니다."<<endl;
}
void division(int x, int y)
{
	static int divi = 0;
	result = x / y;
	cout<<"연산 결과: "<<result<<endl;
	divi++;
	cout<<"나눗셈은 총 "<<divi<<"번 실행되었습니다."<<endl;
}