#include <stdio.h>
#include "bank.h"

int main(void)
{
    H_CASHCARD hCard1 = NULL;
    H_CASHCARD hCard2 = NULL;

    //  銀行口座の作成
    hCard1 = createBankAccount("野口英世", 0x1876);
    hCard2 = createBankAccount("福沢諭吉", 0x1835);

    //  口座情報の表示
    printBalance(hCard1);
    printBalance(hCard2);

    //  預け入れ
    depositMoney(hCard1, 5000);
    depositMoney(hCard2, 500000);

    //  口座情報の表示
    printBalance(hCard1);
    printBalance(hCard2);

    //  引き出し
    withdrawalMoney(hCard1, 0x1876, 1000);
    withdrawalMoney(hCard2, 0x1835, 50000);

    //  口座情報の表示
    printBalance(hCard1);
    printBalance(hCard2);

    //  口座を破棄
    destroyBankAccount(hCard1, 0x1876);
    destroyBankAccount(hCard2, 0x1835);

    return 0;
}