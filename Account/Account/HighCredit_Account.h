#pragma once
#include "Main.h"
class HighCredit_Account : public Nomal_Account
{
private:
	int Add_interRate;
public:
	HighCredit_Account(int ID, int Money, char* Name, int interrate, int Add_interrate);
	~HighCredit_Account();
};