#include <iostream>
using namespace std;
int main()
{
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person=0;

	try 
	{
		cout << "���� �������� �Է��Ͻÿ�: ";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ�: ";
		cin >> persons;

		if (persons == 0) 
			throw persons;
		slices_per_person = pizza_slices / persons;	
		cout << "�ѻ���� ���ڴ� " << slices_per_person << "�Դϴ�." << endl;
	} 
	catch(int e) 
	{
		cout << "����� " << e << " �� �Դϴ�. "<< endl;
	}
	return 0;
}
