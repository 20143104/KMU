#include <iostream>
#include <string>
using namespace std;

class BankAccount {		// ���� ����
private:
	int accountNumber;	// ���� ��ȣ
	string owner;		// ������
	int balance;		// �ܾ��� ǥ���ϴ� ����

public:
	void setBalance(int amount);	// balance�� ���� ������
	int getBalance();		// balance�� ���� ������
	void deposit(int amount);	// ���� �Լ�
	void withdraw(int amount);	// ���� �Լ�
	void print();			// ���� ���� ���
};

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
	cout << "�ܾ��� " << balance << "�Դϴ�." << endl;
}

int main() {
	BankAccount account;

	account.setBalance(0);
	account.deposit(10000);
	account.print();
	account.withdraw(8000);
	account.print();

	return 0;
}
