#include <iostream>
using namespace std;
int dividePizza(int pizza_slices, int persons);

int main()
{
	int pizza_slices = 0;
	int persons = 0;
	int slices_per_person=0;

	try 
	{
		cout << "���� �������� �Է��Ͻÿ�: ";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ�: ";
		cin >> persons;
		slices_per_person =dividePizza(pizza_slices, persons);
		cout << "�ѻ���� ���ڴ� " << slices_per_person << "�Դϴ�." << endl;
	} 
	catch(int e) 
	{
		cout << "����� " << e << " �� �Դϴ�. "<< endl;
	}
	return 0;
}
int dividePizza(int pizza_slices, int persons)
{
		if (persons == 0) 
			throw persons;
		return  pizza_slices / persons;	
}	
