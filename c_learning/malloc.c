#include <stdio.h>
#include <stdlib.h>

#define     D_ARRAY_NUM     (1000)

int main(void)
{
    int i;
    long * pArray = NULL;

    //  long型の1000個分の動的メモリを確保する
    pArray = (long *)malloc(sizeof(long) * D_ARRAY_NUM);

    //  [0]～[999]の動的メモリに0～999の値を順に設定する
    for (i=0;i<D_ARRAY_NUM;i++)
    {
        pArray[i] = i;
    }

    //  [990]～[999]のメモリ内容を画面に表示する
    for (i = D_ARRAY_NUM - 10;i<D_ARRAY_NUM;i++)
    {
        printf("[%d] = %ld\n", i, pArray[i]);
    }

    //  動的メモリを解放する
    free(pArray);
    pArray = NULL;

    return 0;
}