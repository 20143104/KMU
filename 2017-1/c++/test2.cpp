#include <iostream>
#include <fstream>		// 파일 입출력을 하려면 헤더 파일을 포함하여야 한다.
#include<string>
using namespace std;
template <typename T>		// 함수 템플릿으로 정의
void print_array(T a[], int n)
{
	for(int i=0;i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}

template <>		// 템플릿 특수화
void print_array(char a[], int n)	// 매개 변수가 char인 경우에는 이 함수가 호출된다.
{
	cout << a << endl;
}
int main()
{
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person=0;
	try
	{
		cout << "피자 조각수를 입력하시오: ";
		cin >> pizza_slices;
		cout << "사람수를 입력하시오: ";
		cin >> persons;
		if (persons == 0)
			throw string("negative");
		slices_per_person = pizza_slices / persons;
		cout << "한사람당 피자는 " << slices_per_person << "입니다." << endl;
	}
	catch(..)
		{
		cout << "사람이 " << " 명 입니다. "<< endl;
	}
	return 0;
}
