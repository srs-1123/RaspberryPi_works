#include <stdio.h>

void getAreaTriangle(unsigned short bottom, unsigned short height, unsigned long * pArea)
{
    *pArea = bottom * height / 2;
    return;
}

int main(void)
{
    // 底辺
    unsigned short bottom = 1200;

    // 高さ
    unsigned short height = 380;

    // 面積の格納先
    unsigned long area;

    // getAreaTriangle関数の呼び出し
    getAreaTriangle(bottom, height, &area);

    printf("底辺：%d 高さ：%d 面積：%lu", bottom, height, area);

    return 0;
}