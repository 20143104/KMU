#include <iostream>
using namespace std;

class Time {
private:
	int hour; // 0 - 23
	int minute; // 0 - 59
	int second; // 0 - 59
public:
	Time();								// ������
	Time(int h, int m, int s);
	void setTime(int h, int m, int s);
	void print();
};
// ù ��° ������
Time::Time() 
{
	setTime(0, 0, 0);
}

// �� ��° ������
Time::Time(int h, int m, int s) 
{
	setTime(h, m, s);
}

// �ð� ���� �Լ�
void Time::setTime(int h, int m, int s) 
{
	hour = ((h >= 0 && h < 24) ? h : 0); // �ð� ����
	minute = ((m >= 0 && m < 60) ? m : 0); // �� ����
	second = ((s >= 0 && s < 60) ? s : 0); // �� ����
}

// ����:��:�ʡ��� �������� ��� 
void Time::print() 
{
	cout << hour << ":" << minute << ":" << second << endl;
}

int main()
{
	Time time1;

	cout << "�⺻ ������ ȣ�� �� �ð�:  ";
	time1.print();

	// �� ��° ������ ȣ��
	Time time2(13, 27, 6);
	cout << "�ι�° ������ ȣ�� �� �ð�: ";
	time2.print();

	// �ùٸ��� ���� �ð����� �����غ���.
	Time time3(99, 66, 77);
	cout << "�ùٸ��� ���� �ð� ���� �� �ð�: ";
	time3.print();

	return 0;
}
