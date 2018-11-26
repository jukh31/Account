#include "Account.h"

Account::Account(int Money, int ID, char* Name) :balance(Money), account_ID(ID)
{
	int len = strlen(Name) + 1;
	this->name = new char[len];
	strcpy(this->name, Name);
}


int Account::input_ID()
{
	return account_ID;
}

void Account::Deposit(int deposit)
{
	balance += deposit;
}
void Account::Withdrawal(int withdraw)
{
	balance -= withdraw;
}
int Account::CheckBalance(int Bal)
{
	if (balance < Bal) return Err;
	else return TRUE;
}
void Account::Print()
{
	cout << "Account ID =" << account_ID << endl;
	cout << "Name = " << name << endl;
	cout << "Balance = " << balance << endl;
}

Account::~Account()
{
	delete name;
}