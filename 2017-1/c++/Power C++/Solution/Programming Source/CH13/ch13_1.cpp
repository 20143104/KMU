#include <iostream>
#include <string>

using namespace std;

class Employee{
private:
	string name;
	int enumber;
	int salary;
public:
	Employee(string n, int en)
	{
		name = n;
		enumber = en;
	}
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void setEnumber(int en)
	{
		enumber = en;
	}
	int getEnumber()
	{
		return enumber;
	}
	void setSalary(int sal)
	{
		salary = sal;
	}
	int getSalary()
	{
		return salary;
	}
	void computeSalary()
	{
		
	}
};

class SalariedEmployee : public Employee{
private:
	int msalary;
public:
	SalariedEmployee(string n, int en, int sal) : Employee(n, en)
	{
		setSalary(sal);	
	}
	void setMsalary(int msal)
	{
		msalary = msal;
	}
	int getMsalary()
	{
		return msalary;
	}
	void computeSalary()
	{
		msalary = getSalary() / 12;
	}
};
class HourlyEmployee : public Employee{
private:
	int timesal;
	int time;
public:
	HourlyEmployee(string n, int en, int ts, int t) : Employee(n, en)
	{
		timesal = ts;
		time = t;
	}
	void setTimesal(int ts)
	{
		timesal = ts;
	}
	void setTime(int t)
	{
		time = t;
	}
	int getTimesal()
	{
		return timesal;
	}
	int getTime()
	{
		return time;
	}
	void computeSalary(int timesal, int time)
	{
		setSalary(timesal * time);
	}

};

int main()
{
	
	return 0;	
}
