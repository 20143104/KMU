#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

// 0���� 9������ n���� ������ ȭ�鿡 ����Ѵ�. 
void get_random( int n )
{
	int i;
	for( i = 0; i < n; i++ )
		cout << rand() << endl;
}

int main()
{
	// �Ϲ������� ���� �߻����� �õ�(seed)�� ���� �ð����� �����Ѵ�. 
	// ���� �ð��� ������ ������ �޶����� �����̴�. 
	srand( (unsigned)time( NULL ) );
	get_random( 10 );
	
	return 0;
}
