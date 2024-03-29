// ポインタを用いた構造体へのアクセス
#include <stdio.h>

typedef struct
{
    long japaneseLanguage;
    long arithmetic;
    long science;
    long socialStudies;
}S_Subject;

int getAverageSubject(S_Subject pSub[], int num, S_Subject * pAve)
{
    int i;
    if (pSub==NULL)
    {
        return -1;
    }

    for (i=0;i<num;i++)
    {
        pAve->japaneseLanguage += pSub[i].japaneseLanguage;
        pAve->arithmetic += pSub[i].arithmetic;
        pAve->science += pSub[i].science;
        pAve->socialStudies += pSub[i].socialStudies;
    }

    pAve->japaneseLanguage /= num;
    pAve->arithmetic /= num;
    pAve->science /= num;
    pAve->socialStudies /= num;

    return 0;
}
int main(void)
{
    //  学生の教科毎のテスト結果
    S_Subject   point[] = {
        {72, 85, 54, 61}, //  学生A
        {50, 43, 38, 49}, //  学生B
        {89, 92, 87, 78}, //  学生C
        {72, 25, 36, 98}, //  学生D
    };
    int ret = -1;
    S_Subject ave = {0};
    //  getAverageSubject関数の呼び出し
    ret = getAverageSubject(point, sizeof(point)/sizeof(point[0]), &ave);

    // 関数呼び出しの結果
    // 正常なら平均点を表示
    // 異常なら"ERROR"を表示
    if (ret<0)
    {
        printf("ERROR");
    }

    else
    printf("国語: %ld\n算数: %ld\n理科: %ld\n社会: %ld\n", ave.japaneseLanguage, ave.arithmetic, ave.science, ave.socialStudies);
    return 0;
}