#include <stdio.h>

int sortNumber(long * pNumber, int arrayNum)
{
    int i, k;
    long tmp;

    if (pNumber==NULL)
    {
        return -1;
    }

    for (i=0;i<arrayNum;i++)
    {
        for (k=i+1;k<arrayNum;k++)
        {
            if (pNumber[i] > pNumber[k])
            {
                tmp = pNumber[i];
                pNumber[i] = pNumber[k];
                pNumber[k] = tmp;
            }
        }
    }
    return 0;
}

int main(void)
{
    // 入力ケース①
//  long num[] = {10, -290, 3498, 28, -943};

    // 入力ケース②
    long num[] = { 698, 1285, 0, -754, 9832, 1048 ,18};
    int i;

    //  sortNumber関数を呼び出し配列を昇順に並び替えよ
    sortNumber(num, sizeof(num)/sizeof(num[0]));

    for (i = 0 ; i < sizeof(num)/sizeof(num[0]) ; i++)
    {
        printf("%ld\n", num[i]);
    }

    return 0;
}