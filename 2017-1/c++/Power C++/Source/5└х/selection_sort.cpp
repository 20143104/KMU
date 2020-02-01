#include <iostream>
using namespace std;
const int SIZE=10;

void selection_sort(int list[], int n);
void print_list(int list[], int n);

int main()
{
	int grade[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };
	
	// ������ �迭 ���
	cout << "������ �迭" << endl;
	print_list(grade, SIZE);
	
	selection_sort(grade, SIZE);
	
	// ���ĵ� �迭 ���
	cout << "���ĵ� �迭" << endl;
	print_list(grade, SIZE);
	
	return 0;
}

void print_list(int list[], int n)
{
	int i;
	for(i = 0;i < n; i++)
		printf("%d ", list[i]);	
	printf("\n");
}

void selection_sort(int list[], int n)
{
	int i, j, temp, least;
	
	for(i = 0; i < n-1; i++)
	{ 
		least = i;
		
		for(j = i + 1; j < n; j++) 	// �ּҰ� Ž��
			if(list[j] < list[least])
				least = j;
			// i��° ���ҿ� least ��ġ�� ���Ҹ� ��ȯ
			temp = list[i];	
			list[i] = list[least];
			list[least] = temp;
	}
}	
