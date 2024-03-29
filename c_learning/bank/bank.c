#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

#define D_ACCOUNT_NAMESIZE      (64)

// ハンドル: 持っていると特別なサービスを受けられるもの
// キャッシュカードの自作ハンドルを考える

// 銀行口座の構造体
typedef struct {
    char name[D_ACCOUNT_NAMESIZE];//登録氏名
    unsigned short pincode;// 暗証番号
    unsigned long balance;//預金残高
}S_BANK_ACCOUNT;

//------------------------------------------------
//  概  要：銀行口座の作成
//  引  数：name    登録氏名
//          pincode 暗証番号
//  戻り値：キャッシュカードハンドル
//------------------------------------------------
H_CASHCARD createBankAccount(const char * name, unsigned short pincode)
{
    S_BANK_ACCOUNT * pAccount = NULL;

    if (name == NULL)
    {
        return NULL;
    }

    // 口座情報のメモリ領域をヒープメモリに確保
    pAccount = (S_BANK_ACCOUNT *)malloc(sizeof(S_BANK_ACCOUNT));
    if (pAccount == NULL)
    {
        return NULL;
    }

    // 口座情報を初期化
    // errno_t strcpy_s(char *dest, rsize_t dest_size, const char *src) dest: destination（コピー先）の略
    //strcpy_s(pAccount->name, D_ACCOUNT_NAMESIZE, name);
    strcpy(pAccount->name, name);
    pAccount->pincode = pincode;//構造体ポインタのアクセスでは*がいらない
    pAccount->balance = 0;

    return pAccount;
}

// 銀行口座の預金残高照会のサービスの関数化
int printBalance(H_CASHCARD hCard)
{
    // H_CASHCARDは(void *)型なのでアクセスできるよう(S_BANK_ACCOUNT型)にキャストする
    S_BANK_ACCOUNT * pAccount = (S_BANK_ACCOUNT *)hCard;

    if (pAccount == NULL)
    {
        return -1;
    }
    printf("————————–\n");
    printf("氏名：%s様", pAccount->name);
    printf("残高：%ld円", pAccount->balance);
    return 0;
}

// 銀行口座への預け入れサービスの関数化
int depositMoney(H_CASHCARD hCard, unsigned long money)
{
    S_BANK_ACCOUNT * pAccount = (S_BANK_ACCOUNT *)hCard;
    if (pAccount == NULL)
    {
        return -1;
    }

    //  預入のお金を残高に加算
    pAccount->balance += money;

    return 0;
}

int withdrawalMoney(H_CASHCARD hCard, unsigned short pincode, unsigned long reqmoney)
{
    S_BANK_ACCOUNT * pAccount = (S_BANK_ACCOUNT *)hCard;
    if (pAccount == NULL)
    {
        return -1;
    }

    if (pAccount->pincode != pincode)
    {
        return -2;
    }

    if (pAccount->balance < reqmoney)
    {
        return -3;
    }

    pAccount->balance -= reqmoney;

    return reqmoney;
}

int destroyBankAccount(H_CASHCARD hCard, unsigned short pincode)
{
    S_BANK_ACCOUNT * pAccount = (S_BANK_ACCOUNT *)hCard;
    if (pAccount == NULL)
    {
        return -1;
    }

    if (pAccount->pincode != pincode)
    {
        return -2;
    }

    // 口座情報を破棄
    free(pAccount);

    return 0;
}