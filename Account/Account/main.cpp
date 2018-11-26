#include "Main.h"



int main()
{
	Account* account[Size];
	Handler handler(account);

	int sel, NumofAccount = 0;
	int Checking, money;
	int result;
	int buf;
	int CClass;
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
					cout << "Enter Type of Account\n 1.Nomal Account  2.Credit Account" << endl;
					cin >> buf;
					cout << "Enter Account ID" << endl;
					cin >> ID;
					Checking = handler.Check_ID(ID, NumofAccount);
					if (Checking == NM)
					{
						if (buf == Nomal)
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
							account[NumofAccount] = new Nomal_Account(money, ID, name, Base_rate);
							NumofAccount++;
						}
						else if (buf == Credit)
						{
							cout << "Enter your Credit class\n 1.A 2.B 3.C " << endl;
							cin >> buf;
							CClass = handler.Create_CreditClass(buf);
							cout << "Enter Name" << endl;
							cin >> name;
							cout << "Enter Deposit amount" << endl;
							cin >> money;
							if (money <= 0)
							{
								Exception exp(3, "Can't enter negative or 0");
								throw exp;
							}
							account[NumofAccount] = new HighCredit_Account(money, ID, name, Base_rate, CClass);
							NumofAccount++;

						}
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
			cout << "Error CODE [" << exp.Get_ErrCode() << "] " << exp.Get_Message() << endl;
		}

	}
	return 0;
}
