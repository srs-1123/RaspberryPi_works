import cv2
import time
from datetime import datetime

capture = cv2.VideoCapture(0)
if capture.isOpened() is False:
    raise IOError("Cannot open webcam")

try:
    while True:

        ret, frame = capture.read()
        if ret is False:
            raise IOError("Failed to capture frame")

        # 現在時刻を表示
        current_time = datetime.now().strftime("%Y_%m_%d_%H:%M:%S")

        # JPEG形式でフレームを保存
        cv2.imwrite('picture/{}_frame.jpg'.format(current_time), frame)

        # ウィンドウに表示（不要な場合はコメントアウト）
        # cv2.imshow('frame', frame)

        # 現在の時刻と開始時刻の差を計算し、1分になるまで待機
        time.sleep(60)

        if cv2.waitKey(1) == 27:
            break

except KeyboardInterrupt:
    pass

finally:
    # ビデオキャプチャのリリースとOpenCVウィンドウの破棄
    capture.release()
    cv2.destroyAllWindows()