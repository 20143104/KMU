#include <iostream>

using namespace std;

int main()
{
	int com = 0, clang = 0, eng = 0, math = 0;
	float ave = 0;

	cout<<"��ǻ�� ���� ������ ������ �Է��Ͻÿ�.:";
	cin>>com;
	cout<<"C��� ���α׷��� ������ ������ �Է��Ͻÿ�.:";
	cin>>clang;
	cout<<"���� ������ ������ �Է��Ͻÿ�.:";
	cin>>eng;
	cout<<"�Ϲ� ���� ������ ������ �Է��Ͻÿ�.:";
	cin>>math;

	ave = (com + clang + eng + math)/4.0;
	
	cout<<"��������� "<<ave<<"���Դϴ�."<<endl;
	
	
	

	return 0;

}