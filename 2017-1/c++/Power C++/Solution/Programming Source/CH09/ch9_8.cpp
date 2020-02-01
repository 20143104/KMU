#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
	int accountNumber;
	string owner;
	int balance;
	
public:
	int transfer(int amount, BankAccount otherAccount);
	void setBalance(int amount);
	int getBalance();
	void deposit(int amount);
	void withdraw(int amount);
	void print();
};

int BankAccount::transfer(int amount, BankAccount otherAccount)
{
	balance -= amount;
	otherAccount.setBalance(otherAccount.getBalance() + amount);
	
	return balance;
}

void BankAccount::setBalance(int amount)
{
	balance = amount;
}

int BankAccount::getBalance()
{
	return balance;
}

void BankAccount::deposit(int amount)
{
	balance += amount;
}

void BankAccount::withdraw(int amount)
{
	balance -= amount;
}

void BankAccount::print()
{
	cout<<"�ܾ��� "<<balance<<"�Դϴ�."<<endl;
}

int main(){
	BankAccount account, account1;
	
	account.setBalance(0);
	account1.setBalance(0);
	account.deposit(100000);
	account1.deposit(1000);
	cout<<"���� 1�� �ܾ���>> ";
	account.print();
	cout<<"���� 2�� �ܾ���>> ";
	account1.print();
	cout<<"���� 1�� �ܾ���>> ";
	account.withdraw(8000);
	account.print();
	cout<<"-> ���� 1���� 2000���� ���� 2�� ��ü�ϱ�"<<endl;
	cout<<"���� 1�� ��ü�� �� �ܾ��� : "<<account.transfer(2000, account1)<<endl;
	
	return 0;
}