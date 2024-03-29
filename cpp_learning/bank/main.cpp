#include "BankAccount.h"

int main()
{
    //------------------------------------------------
    //  スタックメモリのクラスオブジェクトを生成
    BankAccount hideyo("野口英世", 0x1876);

    hideyo.printBalance();
    hideyo.depositMoney(5000);              //  5,000円預け入れ
    hideyo.printBalance();
    hideyo.withdrawalMoney(0x1876, 1000);   //  1,000円引き出し
    hideyo.printBalance();

    //------------------------------------------------
    //  動的メモリのクラスオブジェクトを生成
    BankAccount * yukichi = new BankAccount("福沢諭吉", 0x1835);

    yukichi->printBalance();
    yukichi->depositMoney(100000);          //  10,0000円預け入れ
    yukichi->printBalance();
    yukichi->withdrawalMoney(0x1835, 30000);//   30,000円引き出し
    yukichi->printBalance();

    delete yukichi;     //  オブジェクトの解放

    return 0;
}