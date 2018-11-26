#pragma once
#include "Main.h"
class Exception
{
private:
	int Err_Code;
	char Err_Code_;
	char Err_Msg[128];
public:
	Exception(int Ecode, const char* Emsg)
	{
		Err_Code = Ecode;
		strcpy(Err_Msg, Emsg);
	}
	~Exception() {}
	int Get_ErrCode() { return Err_Code; }
	char* Get_Message() { return Err_Msg; }

};