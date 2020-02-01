#include <iostream>
#include <string>

using namespace std;

class BankAcct
{
private:
	double money;
	double rate;
	double interest;
public:
	BankAcct(double m)
	{
		money = m;
	}
	void deposit(double m)
	{
		money += m;
	}
	void withdraw(double m)
	{
		money -= m;
	}
	virtual double getInterest()
	{
		return money*rate;
	}
	void setRate(double r)
	{
		rate = r;
	}
	void print()
	{
		cout<<"���ݾ� : "<<money<<endl;
	}
};

class SavingAcct : public BankAcct
{
private:
	
public:
	SavingAcct(int m) : BankAcct(m)
	{
		setRate(0.09);
	}
	void print()
	{	
		cout<<"=================="<<endl;
		cout<<"  ���� ���� ����"<<endl;
		cout<<"=================="<<endl;
		BankAcct::print();
	}
};

class CheckingAcct : public BankAcct
{
private:

public:
	CheckingAcct(int m) : BankAcct(m)
	{
		setRate(0.05);
	}
	void print()
	{
		cout<<"=================="<<endl;
		cout<<"  ���� ���� ����"<<endl;
		cout<<"=================="<<endl;
		BankAcct::print();
	}
};

int main()
{
	SavingAcct sa(5000000);	
	CheckingAcct ca(10000000);
	sa.deposit(100000);
	ca.deposit(150000);
	sa.withdraw(500000);
	ca.withdraw(500000);
	sa.print();
	cout<<"���ھ� : "<<sa.getInterest()<<endl;
	ca.print();
	cout<<"���ھ� : "<<ca.getInterest()<<endl;

	return 0;
}