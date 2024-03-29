#include <stdio.h>

void convConsumptionTax(long * pPrice)
{
    *pPrice *= 1.08;
    return;
}

int main(void)
{
    long price = 10000;

    // convConsumptionTax関数を呼び
    // 消費税後の価格に変換
    convConsumptionTax(&price);


    printf("税込価格：%ld", price);

    return 0;
}