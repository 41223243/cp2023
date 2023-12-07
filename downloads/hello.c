#include <stdio.h>
#include <gd.h>
#include <math.h>

#define PI 3.14159265

void drawKoreanFlag() {
    int flagWidth = 600;
    int flagHeight = 400;

    gdImagePtr img;
    FILE *pngout;

    img = gdImageCreateTrueColor(flagWidth, flagHeight);

    // 設置白色背景
    int white = gdImageColorAllocate(img, 255, 255, 255);
    gdImageFill(img, 0, 0, white);

    // 設置黑色
    int black = gdImageColorAllocate(img, 0, 0, 0);

    // 設置紅色
    int red = gdImageColorAllocate(img, 186, 12, 47);

    // 設置藍色
    int blue = gdImageColorAllocate(img, 0, 32, 91);

    // 設置太極圖案的直徑
    int taijiRadius = flagHeight / 4;

    // 設置太極圖案的中心座標
    int taijiCenterX = flagWidth / 2;
    int taijiCenterY = flagHeight / 2;

    // 繪製太極圖案
    gdImageFilledEllipse(img, taijiCenterX, taijiCenterY, taijiRadius * 2, taijiRadius * 2, red);
    gdImageEllipse(img, taijiCenterX, taijiCenterY, taijiRadius * 2, taijiRadius * 2, black);

    // 設置韓國國旗紅藍相間的色塊
    int blockWidth = flagWidth / 2;

    // 繪製紅藍相間的色塊
    gdImageFilledRectangle(img, 0, 0, blockWidth, flagHeight, blue);
    gdImageFilledRectangle(img, blockWidth, 0, flagWidth, flagHeight, white);

    // 輸出 PNG 文件
    pngout = fopen("korean_flag.png", "wb");
    gdImagePng(img, pngout);

    // 釋放內存
    gdImageDestroy(img);
    fclose(pngout);
}

int main() {
    drawKoreanFlag();
    return 0;
}
