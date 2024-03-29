#include <stdio.h>

int sumArray(long * pArray, int arrayNum, long * pSum)
{
    int i;
    long sum = 0;

    if (pArray==NULL || pSum==NULL)
    {
        return -1;
    }

    for (i=0;i<arrayNum;i++)
    {
        sum += pArray[i];
    }

    *pSum = sum;
    
    return 0;
}

int main(void)
{
    long    num[] = {29, 9642, -3849, 628, 20};
    long    sum = 0;
    int     ret;

    // ケース①
//  ret = sumArray(num, sizeof(num)/sizeof(num[0]), &sum);

    // ケース②
//  ret = sumArray(NULL, sizeof(num)/sizeof(num[0]), &sum);

    //  ケース③
ret = sumArray(num, sizeof(num)/sizeof(num[0]), NULL);

    if (ret == 0)
    {
        printf("sum:%lu", sum);
    }
    else
    {
        printf("ERROR");
    }

    return 0;
}