#include <iostream>
using namespace std;
int mode;	// ���� ���� mode

namespace Graphics {
	int mode;
	int x, y;
	void draw() { cout << "Graphics �̸� ���� ���� draw()" << endl; };	
	void message() { cout << "Graphics �̸� ���� ���� message()" << endl; };	
}

namespace Network {
	int mode, speed;
	void send(char *) { cout << "Graphics �̸� ���� ���� send()" << endl; };	
	void message() { cout << "Network �̸� ���� ���� message()" << endl; };	
}

int main()
{
	//x = y = 100;		// ������ ����!
	//speed = 22900;		// ������ ����!
	//draw();		// ������ ����!

	mode = 1;		// ���� ����
	Graphics::mode = 1;	
	Network::mode = 2;	

	Graphics::message();
	Network::message();
	return 0;
}
