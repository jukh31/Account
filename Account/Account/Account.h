#pragma once
#include "Main.h"
class Account
{
private:
	int balance;
	int account_ID;
	char* name;
public:
	Account(int Money, int ID, char* Name);
	~Account();

	int input_ID();
	void Deposit(int deposit);
	void Withdrawal(int withdraw);
	int CheckBalance(int bal);
	void Print();

};