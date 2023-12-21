#include <stdio.h>
#include <math.h>
#include <gd.h>

#define WIDTH 600
#define HEIGHT 400

void drawTaiChi(gdImagePtr im) {
    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    int radius = HEIGHT / 3;

    // 繪製黑色太極圓
    gdImageFilledArc(im, centerX, centerY, radius * 2, radius * 2, 0, 360, gdTrueColor(0, 0, 0));

    // 計算兩個半圓的圓心座標
    int leftCenterX = centerX - radius / 2;
    int rightCenterX = centerX + radius / 2;

    // 繪製紅色太極圓
    gdImageFilledArc(im, leftCenterX, centerY, radius, radius, 0, 180, gdTrueColor(255, 0, 0));

    // 繪製藍色太極圓
    gdImageFilledArc(im, rightCenterX, centerY, radius, radius, 180, 360, gdTrueColor(0, 0, 255));
}

int main() {
    // 創建一個寬高比為3:2的圖像
    gdImagePtr im = gdImageCreate(WIDTH, HEIGHT);

    // 設置背景色為白色
    int white = gdImageColorAllocate(im, 255, 255, 255);
    gdImageFill(im, 0, 0, white);

    // 繪製太極圖
    drawTaiChi(im);

    // 將圖片保存為 PNG 檔案
    FILE *output = fopen("tai_chi.png", "wb");
    if (output) {
        gdImagePng(im, output);
        fclose(output);
    }

    // 釋放內存
    gdImageDestroy(im);

    return 0;
}
