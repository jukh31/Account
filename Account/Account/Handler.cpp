#include "Handler.h"


Handler::Handler(Account** mAccount)
{
	account = mAccount;
}

int Handler::Check_ID(int ID, int NumofAccount)
{
	for (int i = 0; i < NumofAccount; i++)
	{
		if (ID == account[i]->input_ID())
			return i;
	}
	return NM;
}
int Handler::Check_ID(int ID)
{
	for (int i = 0; i < Size; i++)
	{
		if (ID == account[i]->input_ID())
			return i;
	}
	return NM;
}
void Handler::Print_All(int NumofAccount)
{
	for (int i = 0; i < NumofAccount; i++)
		account[i]->Print();
}


void Handler::Menu(void)
{
	cout << "---------Menu---------" << endl;
	cout << "1 계좌 개설\n" << endl;
	cout << "2 입금\n" << endl;
	cout << "3 출금\n" << endl;
	cout << "4 전체 계좌 출력\n" << endl;
	cout << "5 종료\n" << endl;
}