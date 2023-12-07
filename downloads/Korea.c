#include <stdio.h>
#include <gd.h>

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

    // 設置四個黑色菱形的座標
    int diamondSize = flagHeight / 16;

    int diamond1X = flagWidth / 2 - diamondSize / 2;
    int diamond1Y = flagHeight / 4 - diamondSize / 2;

    int diamond2X = flagWidth / 2 - diamondSize / 2;
    int diamond2Y = flagHeight * 3 / 4 - diamondSize / 2;

    int diamond3X = flagWidth / 4 - diamondSize / 2;
    int diamond3Y = flagHeight / 2 - diamondSize / 2;

    int diamond4X = flagWidth * 3 / 4 - diamondSize / 2;
    int diamond4Y = flagHeight / 2 - diamondSize / 2;

    // 繪製四個黑色菱形
    gdImageFilledRectangle(img, diamond1X, diamond1Y, diamond1X + diamondSize, diamond1Y + diamondSize, black);
    gdImageFilledRectangle(img, diamond2X, diamond2Y, diamond2X + diamondSize, diamond2Y + diamondSize, black);
    gdImageFilledRectangle(img, diamond3X, diamond3Y, diamond3X + diamondSize, diamond3Y + diamondSize, black);
    gdImageFilledRectangle(img, diamond4X, diamond4Y, diamond4X + diamondSize, diamond4Y + diamondSize, black);

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
