#include <iostream>
using namespace std;


class NoPersonException
{
public:
	NoPersonException();
	NoPersonException(int p) { persons = p; };
	int get_persons() { return persons; };
private:
	int persons;
};

int main()
{
	int pizza_slices = 12;
	int persons = -1;
	int slices_per_person=0;

	try {
		cout << "���� �������� �Է��Ͻÿ�: ";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ�: ";
		cin >> persons;
		if( persons <= 0 ) throw NoPersonException(persons);		// ���� �߻�!
		slices_per_person = pizza_slices / persons;		
		cout << "�ѻ���� ���ڴ� " << slices_per_person << "�Դϴ�." << endl;
	} 
	catch (NoPersonException e) 
	{
		cout << "����: ����� " << e.get_persons() << "�� �Դϴ�" << endl;
	}
	return 0;
}
