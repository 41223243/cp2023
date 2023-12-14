#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_south_korea_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int x, int y, int size, int color);

int main() {
    // 設定圖片大小（這裡僅為示例，實際大小需根據需求調整）
    int width = 600;
    int height = 400;

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_korean_flag(img);

    FILE *outputFile = fopen("./korean_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_korean_flag(gdImagePtr img) {
  int width = gdImageSX(img)
  int height = gdImageSX(img)
  int white,black,red,blue;
  int red=gdImageColorAllocate(img, 255,0,0);
  int white=gdImageColorAllocate(img, 255,255,255);
  int black=gdImageColorAllocate(img, 0,0,0);
  int blue=gdImageColorAllocate(img, 0,0,255);
}

void draw_white_sun(gdImagePtr img, int x, int y, int size, int color) {
  int x,y,size,color;
}
