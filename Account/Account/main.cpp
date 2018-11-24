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
class Check
{
private:
	Account** account;
public:
	Check(Account** mAccount);
	int Check_ID(int ID, int NumofAccount);
	int Check_ID(int ID);
	void Print_All(int NumofAccount);

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
Check::Check(Account** mAccount)
{
	account = mAccount;
}

int Check::Check_ID(int ID, int NumofAccount)
{
	for (int i = 0; i < NumofAccount; i++)
	{
		if (ID == account[i]->input_ID())
			return i;
	}
	return NM;
}
int Check::Check_ID(int ID)
{
	for (int i = 0; i < Size; i++)
	{
		if (ID == account[i]->input_ID())
			return i;
	}
	return NM;
}
void Check::Print_All(int NumofAccount)
{
	for (int i = 0; i < NumofAccount; i++)
		account[i]->Print();
}


void Menu(void)
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
	Check check(account);
	int sel, NumofAccount = 0;
	int Checking, money;
	int result;
	char name[30] = {};
	while (1)
	{
		Menu();
		cout << "Select " << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			system("cls");
			int ID;
			cout << "Creating Account\n" << endl;
			cout << "Enter Account ID" << endl;
			cin >> ID;
			Checking = check.Check_ID(ID, NumofAccount);
			if (Checking == NM)
			{
				cout << "Enter Name" << endl;
				cin >> name;
				cout << "Enter Deposit amount" << endl;
				cin >> money;
				account[NumofAccount] = new Account(money, ID, name);
				NumofAccount++;
			}
			else
			{
				cout << "Used ID" << endl;
			}
			break;
		case 2:
			system("cls");
			cout << "deposit" << endl;
			cout << "Enter Account ID" << endl;
			cin >> ID;
			Checking = check.Check_ID(ID);
			if (Checking == NM)
				cout << "No Match" << endl;
			else
			{
				cout << "Enter Deposit Amount" << endl;
				cin >> money;
				account[Checking]->Deposit(money);
				cout << "Success" << endl;

			}
			break;
		case 3:
			system("cls");
			cout << "withdraw" << endl;
			cout << "Ener Account ID" << endl;
			cin >> ID;
			Checking = check.Check_ID(ID);
			if (Checking == NM)
				cout << "No Match" << endl;
			else
			{
				cout << "Enter Withdrawal Amount" << endl;
				cin >> money;
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
			check.Print_All(NumofAccount);
			break;
		case 5:
			exit(0);

			break;
		}
	}
	return 0;
}

