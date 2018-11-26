#pragma once
#include <iostream>
#include <cstring>
#include "Account.h"
#include "Handler.h"
#include "Exception.h"
#include "HighCredit_Account.h"
#include "Nomal_Account.h"

using namespace std;
#define TRUE 2
#define Err 3
#define NM 99
#define Size 101
typedef enum { LV_A = 7, LV_B = 4, LV_C = 2, NO_LV = 0 }LEVEL;
typedef enum { Nomal = 1, Credit = 2 }Account_Type;