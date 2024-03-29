#ifndef BANK_H
#define BANK_H
//------------------------------------------------

//------------------------------------------------
//  マクロ定義(Macro definition)
//------------------------------------------------

//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------
//  キャッシュカードハンドル
typedef void * H_CASHCARD;

//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------
H_CASHCARD createBankAccount(const char * name, unsigned short pincode);
int printBalance(H_CASHCARD hCard);
int depositMoney(H_CASHCARD hCard, unsigned long money);
int withdrawalMoney(H_CASHCARD hCard, unsigned short pincode, unsigned long reqmoney);
int destroyBankAccount(H_CASHCARD hCard, unsigned short pincode);

//------------------------------------------------
#endif