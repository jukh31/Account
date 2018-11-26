#pragma once
#include "Main.h"


class Handler
{
private:
	Account** account;
public:
	Handler(Account** mAccount);
	int Check_ID(int ID, int NumofAccount);
	int Check_ID(int ID);
	void Print_All(int NumofAccount);
	void Menu();

};