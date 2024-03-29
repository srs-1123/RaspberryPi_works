#ifndef BankAccount_h
#define BankAccount_h

#define D_ACCOUNT_NAMESIZE  (64) //氏名サイズ

class BankAccount
{
private:
    char mName[D_ACCOUNT_NAMESIZE];  // キャッシュカードを利用する人の名前を管理
    unsigned short mPincode;         // 不正利用防止のため、16進数4桁の暗証番号を管理
    unsigned long mBalance;          // 預け入れや引き出しによって変わる預金の残高を管理

public:
    BankAccount(const char * name, unsigned short pincode);
    int printBalance();
    int depositMoney(unsigned long money);
    int withdrawalMoney(unsigned short pincode, unsigned long reqmoney);
    ~BankAccount();
};

#endif