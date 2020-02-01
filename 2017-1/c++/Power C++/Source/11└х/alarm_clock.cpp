#include <iostream>
#include <string>
using namespace std;

// �ð��� ��Ÿ���� Ŭ���� 
class Time {
private:
	int time;		// �ð�
	int minute;		// ��
	int second;		// ��
public:
	Time();		// ����Ʈ ������
	Time(int t, int m, int s);	// ������
	void print();		// ��ü�� ���� ���
};

Time::Time() {		// ����Ʈ ������
	time = 0;
	minute = 0;
	second = 0;
}
Time::Time(int t, int m, int s) {	// ������
	time = t;
	minute = m;
	second = s;
}
void Time::print()	// ��ü�� ������ ���
{
	cout << time << "�� " << minute << "�� " << second << "�� \n";
}

// �˶� �ð踦 ��Ÿ����.
class AlarmClock {
private:
	Time currentTime;	// ���� �ð�
	Time alarmTime;	// �˶� �ð�
public:
	AlarmClock(Time a, Time c);	// ������
	void print();		// ��ü�� ���� ���
};

AlarmClock::AlarmClock(Time a, Time c) {	// ������
	alarmTime = a;		// ��ü�� ����ȴ�. 
	currentTime = c;		// ��ü�� ����ȴ�. 
}

void AlarmClock::print()
{
	cout << "���� �ð�: ";
	currentTime.print();
	cout << "�˶� �ð�: ";
	alarmTime.print();
}

int main()
{
	Time alarm(6, 0, 0);
	Time current(12, 56, 34);
	AlarmClock c(alarm, current);

	c.print();
	return 0;
} 
