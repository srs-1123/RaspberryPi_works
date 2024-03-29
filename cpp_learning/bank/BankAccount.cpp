#include <stdio.h>
#include <string.h>
#include "BankAccount.h"

BankAccount::BankAccount(const char * name, unsigned short pincode)
{
    strcpy(mName, name);
    mPincode = pincode;       
    mBalance = 0;  
}

int BankAccount::printBalance()
{
    printf("————————–\n");
    printf("氏名：%s様\n", mName);
    printf("残高：%d円\n", (int)mBalance);

    return 0;
}

int BankAccount::depositMoney(unsigned long money)
{
    mBalance += money;

    return 0;
}

int BankAccount::withdrawalMoney(unsigned short pincode, unsigned long reqmoney)
{
    if (mPincode != pincode)
    {
        return -2;
    }

    if (mBalance < reqmoney)
    {
        return -3;
    }

    mBalance -= reqmoney;

    return reqmoney;
}

BankAccount::~BankAccount()
{
    // 特に処理なし
}