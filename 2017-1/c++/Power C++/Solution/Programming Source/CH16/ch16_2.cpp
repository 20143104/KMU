#include <iostream>

using namespace std;

class NegativeBalance
{
public:
	void display(){	cout<<"NegativeBalance "<<endl;	}
};

class BankAccount
{
	int balance;
public:
	BankAccount() { balance = 0; }
	BankAccount(int b) { balance = b; }
	int getBalance() { return balance; }
	void setBalance(int b) { balance = b; }
	void deposit(int amount) { balance+= amount; }
	void withdraw(int amount)
	{
		if( amount > balance ) throw NegativeBalance();
		balance-= amount; 
	}
	void display() { cout<<"현재 잔액은 : "<<balance<<endl;}
};


int main()
{	
	BankAccount myAcount(1000000);

	cout<<"myAccount 계좌가 생성 되었습니다."<<endl;
	try{
		myAcount.deposit(20000);
		myAcount.display();
		myAcount.withdraw(1020001);
		myAcount.display();	
	}
	catch(NegativeBalance& e)
	{
		e.display();
	}
	return 0;
}	