// 関数ポインタをまとめて１つの配列に代入
#include <stdio.h>

typedef void (* FP_CALCULATION)(long, long);

void addition(long num1, long num2)
{
    printf("%ld + %ld => %ld\n", num1, num2, num1 + num2);

    return;
}

void subtraction(long num1, long num2)
{
    printf("%ld - %ld => %ld\n", num1, num2, num1 - num2);

    return;
}

void multiplication(long num1, long num2)
{
    printf("%ld * %ld => %ld\n", num1, num2, num1 * num2);

    return;
}

void division(long num1, long num2)
{
    printf("%ld / %ld => %ld\n", num1, num2, num1 / num2);

    return;
}

int main(void)
{
    // 関数ポインタの配列
    FP_CALCULATION  pfunc[] = {
        addition,       // 加算
        subtraction,    // 減算
        multiplication, // 乗算
        division,       // 徐算
    };
    int i;

    for (i = 0; i < sizeof(pfunc) / sizeof(pfunc[0]); i++)
    {
        //  関数ポインタの配列から四則演算を実施
        //  第1引数は150、第2引数は30とする
        pfunc[i](150, 30);

    }

    return 0;
}