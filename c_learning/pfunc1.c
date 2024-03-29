#include <stdio.h>

typedef void (* FP_HELLO)(void);

void hello(void)
{
    printf("Hello\n");
}

int main(void)
{
    // 関数ポインタ変数を定義
    FP_HELLO pfunc = NULL;

    // 関数ポインタに関数を設定
    pfunc = hello;

    // 関数ポインタから関数を呼び出す
    pfunc(%ld);

    return 0;
}