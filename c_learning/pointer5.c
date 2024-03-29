// ポインタを用いた構造体へのアクセス
#include <stdio.h>

typedef struct
{
	double longitude;  // 経度
	double latitude;  // 緯度
}S_Coordinate;

int getTokyoPosition(S_Coordinate * pPos)
{
    if (pPos==NULL)
    {
        return -1;
    }
    pPos->latitude = 35.658581;
    pPos->longitude = 139.745433;

    return 0;
}

int main(void)
{
    //  S_Coordinate構造体変数の定義
    S_Coordinate pos;
    S_Coordinate * pPos = &pos;
    int ret = -1;

    //  getTokyoTowerPosition関数の呼び出し
    ret = getTokyoPosition(pPos);

    //  関数呼び出しの結果
    //  正常なら緯度経度座標を表示
    //  異常なら"ERROR"を表示
    if (ret<0)
    {
        printf("ERROR");
    }
    else
    {
        printf("緯度:%lf経度:%lf", pos.latitude, pos.longitude);
    }
    return 0;
}