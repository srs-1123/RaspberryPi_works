#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

int main()
{
    cv::VideoCapture cap(0);//デバイスのオープン

    if(!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
    {
        //読み込みに失敗したときの処理
        return -1;
    }

    // デバイスを明示的に解放する
    cap.release();

    return 0;
}