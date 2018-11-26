#pragma once
#include "Main.h"

class Nomal_Account : public Account
{
private:
	int interRate;
public:
	Nomal_Account(int ID, int Money, char* Name, int interrate);
	~Nomal_Account();


};
