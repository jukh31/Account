#include <iostream>
#include <cstring>
using namespace std;
#define TRUE 2
#define Err 3
#define NM 99
#define Size 101

class Account
{
private:
	int money;
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
class Exception
{
private:
	int Err_Code;
	char Err_Code_;
	char Err_Msg[128];
public:
	Exception(int Ecode,const char* Emsg)
	{
		Err_Code = Ecode;
		strcpy(Err_Msg, Emsg);
	}
	~Exception() {}
	int Get_ErrCode() { return Err_Code; }
	char* Get_Message() { return Err_Msg; }

};


Account::Account(int Money, int ID, char* Name) :money(Money), account_ID(ID)
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
	money += deposit;
}
void Account::Withdrawal(int withdraw)
{
	money -= withdraw;
}
int Account::CheckBalance(int Bal)
{
	if (money < Bal) return Err;
	else return TRUE;
}
void Account::Print()
{
	cout << "Account ID =" << account_ID << endl;
	cout << "Name = " << name << endl;
	cout << "Balance = " << money << endl;
}

Account::~Account()
{
	delete name;
}
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

int main()
{
	Account* account[Size];
	Handler handler(account);
	
	int sel, NumofAccount = 0;
	int Checking, money;
	int result;
	char name[30] = {};
	while (1)
	{
		handler.Menu();
		try
		{
			cout << "Select " << endl;
			cin >> sel;
			if (sel < 1 || sel>5)
			{
				Exception exp(1, "Enter Correct Command");
				throw exp;
			}
			switch (sel)
			{
			case 1:
				
				int ID;
				system("cls");
				if (NumofAccount < Size)
				{
					cout << "Creat new Account\n" << endl;
					cout << "Enter Account ID" << endl;
					cin >> ID;
					Checking = handler.Check_ID(ID, NumofAccount);
					if (Checking == NM)
					{
						cout << "Enter Name" << endl;
						cin >> name;

						cout << "Enter Deposit amount" << endl;
						cin >> money;
						if (money <= 0)
						{
							Exception exp(3, "Can't enter negative or 0");
							throw exp;
						}
						account[NumofAccount] = new Account(money, ID, name);
						NumofAccount++;
					}
					else
					{
						Exception exp(4, "Used ID");
						throw exp;
					}
				}
				else
				{
					Exception exp(5, "No More Space");
					throw exp;
				}
				break;
			case 2:
				system("cls");
				cout << "deposit" << endl;
				cout << "Enter Account ID" << endl;
				cin >> ID;
				Checking = handler.Check_ID(ID);
				if (Checking == NM)
				{
					Exception exp(6, "No Match ID");
					throw exp;
				}
				else
				{
					cout << "Enter Deposit Amount" << endl;
					cin >> money;
					if (money <= 0)
					{
						Exception exp(3, "Can't enter negative or 0");
						throw exp;
					}
					account[Checking]->Deposit(money);
					cout << "Success" << endl;
				}
				break;
			case 3:
				system("cls");
				cout << "withdraw" << endl;
				cout << "Ener Account ID" << endl;
				cin >> ID;
				Checking = handler.Check_ID(ID);
				if (Checking == NM)
				{
					Exception exp(6, "No Match ID");
					throw exp;
				}
				else
				{
					cout << "Enter Withdrawal Amount" << endl;
					cin >> money;
					if (money <= 0)
					{
						Exception exp(3, "Can't enter negative or 0");
						throw exp;
					}
					result = account[Checking]->CheckBalance(money);
					if (result == TRUE)
					{
						account[Checking]->Deposit(money);
						cout << "Success" << endl;
					}
					else
						cout << "Insufficient cash" << endl;
				}
				break;
			case 4:
				system("cls");
				handler.Print_All(NumofAccount);
				break;
			case 5:
				exit(0);

				break;
			}
		}
		catch (Exception &exp)
		{
			cout << "Error CODE [" << exp.Get_ErrCode()<<"] "<<exp.Get_Message() <<endl;
		}

	}
	return 0;
}
