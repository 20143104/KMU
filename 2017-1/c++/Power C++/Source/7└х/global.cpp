#include <iostream>
using namespace std;

int mode;	// ���� ���� mode
void message()
{
	cout << "���� ���� ���� message()" << endl; 	
}

namespace Graphics {
	int mode;
	int x, y;
	void draw() { cout << "Graphics �̸� ���� ���� draw()" << endl; };	
	void message() { cout << "Graphics �̸� ���� ���� message()" << endl; };	
}

int main()
{
	using namespace Graphics;

	//mode = 1;		// ������ ����!!
	Graphics::mode = 1;	// Graphics ���� ���� mode
	::mode = 1;		// ���� ���� mode

	//message();		// ������ ����
	Graphics::message();	// Graphics ���� ���� message()
	::message();		// ���� �Լ�
	return 0;
}
