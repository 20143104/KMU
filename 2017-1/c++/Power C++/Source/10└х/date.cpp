#include <iostream>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date();						// ����Ʈ ������
	Date(int year);					// ������
	Date(int year, int month, int day);			// ������
	void setDate(int year, int month, int day);		// ��� �Լ�
	void print();						// ��� �Լ�
};

Date::Date()	// ����Ʈ ������
{		
	year = 2010;
	month = 1;
	day = 1;
}
Date::Date(int year) // ������
{				
	setDate(year, 1, 1);
}
Date::Date(int year, int month, int day) // ������
{	
	setDate(year, month, day);
}
void Date::setDate(int year, int month, int day) 
{
	this->month = month;		// this�� ���� ��ü�� ����Ų��.
	this->day = day;
	this->year = year;
}
void Date::print()
{
	cout << year << "�� " << month <<  "�� " << day << "��" << endl;
}

int main()
{
	Date date1(2009, 3, 2); 	// 2009.3.2
	Date date2(2009); 		// 2009.1.1
	Date date3; 			// 2010.1.1

	date1.print();
	date2.print();
	date3.print();
	return 0;
}
_
