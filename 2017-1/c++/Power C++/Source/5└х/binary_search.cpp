#include <iostream>
using namespace std;

const int SIZE=10;

int binary_search(int list[], int n, int key);

int main(void)
{
	int key;
	int grade[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	cout << "Ž���� ���� �Է��Ͻÿ�:";
	cin >> key;
	cout << "Ž�� ���=" << binary_search(grade, SIZE, key) << endl;
	
	return 0;
}

int binary_search(int list[], int n, int key)
{
	int low, high, middle;
	
	low = 0;
	high = n-1;
	
	while( low <= high ){       // ���� ���ڵ��� ����������
		middle = (low + high)/2;   	// �߰� ��� ����
		if( key == list[middle] )	// ��ġ�ϸ� Ž�� ����
			return middle;
		else if( key > list[middle] )// �߰� ���Һ��� ũ�ٸ�
			low = middle + 1;	// ���ο� ������ low ����
		else 
			high = middle - 1;	// ���ο� ������ high ����
	}   
	return -1;
}
