#include <iostream>

using std::ostream;
using std::istream;
using std::endl;
using std::cout;
using std::cin;

class Time
{
	friend ostream& operator<<(ostream& os, const Time& c);
	friend istream& operator>>(istream& os, const Time& c);
	
	int hour;
	int minute;
	int second;
public:
	Time(){
		hour = 0;
		minute = 0;
		second = 0;
	}
	Time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}
	~Time(){}
	Time operator+(int n)
	{
		int h, m, s;
		int tot = 0;
		Time t;

		tot = this->second + (this->minute * 60) + (this->hour * 60 * 60);
		tot += n;

		h = tot / 3600;
		m = (tot % 3600) / 60;
		s = (tot % 3600) % 60;
		t.hour = h;
		t.minute = m;
		t.second = s;
		
		return t;
	}
	Time operator-(int n)
	{
		int h, m, s;
		int tot = 0;
		Time t;
		
		tot = this->second + (this->minute * 60) + (this->hour * 60 * 60);
		tot -= n;
	
		h = tot / 3600;
		m = (tot % 3600) / 60;
		s = (tot % 3600) % 60;
		t.hour = h;
		t.minute = m;
		t.second = s;
		
		return t;
		
	}
	bool operator<(Time p)
	{
		int tot = 0;
		int tot1 = 0;
		
		tot = this->second + (this->minute * 60) + (this->hour * 60 * 60);
		tot1 = p.second + (p.minute * 60) + (p.hour * 60 * 60);
		
		if(tot > tot1)
			return true;
		else
			return false;
	}
	bool operator>(Time p)
	{
		int tot = 0;
		int tot1 = 0;
		
		tot = this->second + (this->minute * 60) + (this->hour * 60 * 60);
		tot1 = p.second + (p.minute * 60) + (p.hour * 60 * 60);
		
		if(tot < tot1)
			return true;
		else
			return false;

	}
	bool operator==(Time p)
	{
		int tot = 0;
		int tot1 = 0;
		
		tot = this->second + (this->minute * 60) + (this->hour * 60 * 60);
		tot1 = p.second + (p.minute * 60) + (p.hour * 60 * 60);
		
		if(tot == tot1)
			return true;
		else
			return false;
	}
	bool operator!=(Time p)
	{
		int tot = 0;
		int tot1 = 0;
		
		tot = this->second + (this->minute * 60) + (this->hour * 60 * 60);
		tot1 = p.second + (p.minute * 60) + (p.hour * 60 * 60);
		
		if(tot != tot1)
			return true;
		else
			return false;
	}
	void display()
	{
		cout<<hour<<":"<<minute<<":"<<second<<endl;
	}
};

ostream& operator<<(ostream& os, const Time& c)
{
	os<<c.hour<<":"<<c.minute<<":"<<c.second<<endl;
	return os;
}

istream& operator>>(istream& is, const Time& c)
{
	is>>(int)c.hour>>(int)c.minute>>(int)c.second;
	return is;
}


int main()
{
	Time start(1,0,0);
	cout<<"end = start + 1000"<<endl;
	Time end = start + 1000; // 1000ÃÊ ÈÄ
	end.display();
	cout<<"end = end - 500"<<endl;
	end = end - 500;
	end.display();
	bool temp = start<end;
	cout<<"start < end : "<< temp <<endl;
	temp = start>end;
	cout<<"start > end : "<< temp <<endl;
	Time t;
	cout<<"cin>> ";
	cin>>t;
	cout<<"cout<< ";
	t.display();

	return 0;
}