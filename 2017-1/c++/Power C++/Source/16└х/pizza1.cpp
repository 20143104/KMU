#include <iostream>
using namespace std;
int main()
{
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person=0;

	cout << "���� �������� �Է��Ͻÿ�: ";
	cin >> pizza_slices;
	cout << "������� �Է��Ͻÿ�: ";
	cin >> persons;
	slices_per_person = pizza_slices / persons;	
	cout << "�ѻ���� ���ڴ� " << slices_per_person << "�Դϴ�." << endl;

	return 0;
}
