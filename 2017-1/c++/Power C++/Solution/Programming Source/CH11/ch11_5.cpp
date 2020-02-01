#include <iostream>

using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h = 0, int m = 0, int s = 0):hour(h), minute(m), second(s){ }
	~Time(){ }
	void setHour(int h){ hour = h; }
	void setMinute(int m){ minute = m; }
	void setSecond(int s){ second = s; }
	int getHour(){ return hour; }
	int getMinute(){ return minute; }
	int getSecond(){ return second; }
	void print(){ cout<<"�ð���"<<hour<<":"<<minute<<":"<<second<<endl;}
};

bool isEqual(Time t1, Time t2)
{
	if( (t1.getHour() == t2.getHour()) && (t1.getMinute() == t2.getMinute()) && (t1.getSecond() == t2.getSecond()))
		return true;
	else
		return false;
}

/*bool isEqual(Time& t1, Time& t2)
{
	if( (t1.getHour() == t2.getHour()) && (t1.getMinute() == t2.getMinute()) && (t1.getSecond() == t2.getSecond()))
		return true;
	else
		return false;
}
*/
bool isEqual(Time *pt1, Time *pt2)
{
	if( (pt1->getHour() == pt2->getHour()) && (pt1->getMinute() == pt2->getMinute()) && (pt1->getSecond() == pt2->getSecond()))
		return true;
	else
		return false;
}

void main()
{
	Time t1,t2;
	Time &tt1 = t1, &tt2 =t2;
	Time *pt1 = &t1, *pt2 = &t2;
	
	t1.setHour(10);
	t1.setMinute(15);
	t1.setSecond(20);

	t2.setHour(10);
	t2.setMinute(15);
	t2.setSecond(20);
	
	cout<<"t1 ";
	t1.print();
	cout<<"t2 ";
	t2.print();

	cout<<"t1�� t2�� �ð��� �����ϴ�. : "<<isEqual(tt1,tt2)<<endl;
	cout<<"t1�� t2�� �ð��� �����ϴ�. : "<<isEqual(pt1,pt2)<<endl;
}

// bool isEqual(Time t1, Time t2);
// bool isEqual(Time& t1, Time& t2);
// �Ұ����մϴ�. ���޵Ǵ� ������ �׳� ������� ������ ��������� �����Ϸ��μ���
// �˼��� ��� ������ �߻��ϰ� �˴ϴ�.