#include <iostream>
#include <assert.h>
using namespace std;

// ���� �迭�� ��Ÿ����. 
class MyArray {
	friend ostream& operator<<(ostream &, const MyArray &);	// ��� ������ <<
private:
	int *data;		// �迭�� ������
	int size;		// �迭�� ũ��

public:
	MyArray(int size = 10);	// ����Ʈ ������
	~MyArray();			// �Ҹ���

	int getSize() const;		// �迭�� ũ�⸦ ��ȯ
	MyArray& operator=(const MyArray &a);	// = ������ �ߺ� ����
	int& operator[](int i);	// [] ������ �ߺ�: ������
};

MyArray::MyArray(int s) {
	size = (s > 0 ? s : 10);    // ����Ʈ ũ�⸦ 10���� �Ѵ�.
	data = new int[size];      // ���� �޸� �Ҵ�

	for (int i = 0; i < size; i++)
		data[i] = 0;           // ��ҵ��� �ʱ�ȭ 
}

MyArray::~MyArray() {
	delete [] data;                       // ���� �޸� �ݳ�
	data = NULL;
}

MyArray& MyArray::operator=(const MyArray& a) {
	if (&a != this) {			// �ڱ� �ڽ������� üũ
		delete [] data;			// ���� �޸� �ݳ�
		size = a.size;			// ���ο� ũ�⸦ ����
		data = new int[size];		// ���ο� ���� �޸� �Ҵ� 

		for (int i = 0; i < size; i++)
			data[i] = a.data[i];	// ������ ����
	}
	return *this;				// a = b = c�� ���� ��츦 ���
}

int MyArray::getSize() const 
{ 
	return size; 
}

int& MyArray::operator[](int index) {
	assert(0 <= index && index < size);	// �ε����� ������ ���� ������ ����
	return data[index]; 
}

// ������ �Լ� ����
ostream& operator<<(ostream &output, const MyArray &a) {
	int i;
	for (i = 0; i < a.size; i++) {
		output << a.data[i] << ' ';
	}
	output << endl;
	return output;			// cout << a1 << a2 << a3�� ���� ��� ���
}

int main()
{
	MyArray a1(10);

	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;
	cout << a1 ;

	return 0;
}		
