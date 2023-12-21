#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_roc_flag(gdImagePtr img);

// 函式原型
int circleLineIntersection(float cx, float cy, float radius, float x1, float y1, float x2, float y2, float *intersection1_x, float *intersection1_y, float *intersection2_x, float *intersection2_y);

int main() {
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("roc_flag_in_gd.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}

void draw_roc_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue;
    int center_x = (int)(width / 4);
    int center_y = (int)(height / 4);
    int sun_radius = (int)(width / 8);
    int white_circle_dia = sun_radius;
    int blue_circle_dia = white_circle_dia + white_circle_dia * 2 / 15;

    red = gdImageColorAllocate(img, 255, 0, 0);
    white = gdImageColorAllocate(img, 255, 255, 255);
    blue = gdImageColorAllocate(img, 0, 0, 149);

    gdImageFilledRectangle(img, 0, 0, width, height, red);
    gdImageFilledRectangle(img, 0, 0, (int)(width / 2.0), (int)(height / 2.0), blue);

    // 利用一個藍色大圓與白色小圓畫出藍色環狀
    gdImageFilledEllipse(img, center_x, center_y, blue_circle_dia, blue_circle_dia, blue);
    gdImageFilledEllipse(img, center_x, center_y, white_circle_dia, white_circle_dia, white);

    // 連接第二組ABED的白線
    int ax = 429;
    int ay = 125;
    int bx = 279;
    int by = 165;
    int ex = 170;
    int ey = 274;
    int dx = 170;
    int dy = 274;

    gdImageLine(img, ax, ay, bx, by, white);
    gdImageLine(img, bx, by, ex, ey, white);
    gdImageLine(img, ex, ey, dx, dy, white);
    gdImageLine(img, dx, dy, ax, ay, white);

    // 計算圓心與ABED三角形的交點
    float intersection1_x, intersection1_y, intersection2_x, intersection2_y;

    if (circleLineIntersection(center_x, center_y, sun_radius, ax, ay, bx, by, &intersection1_x, &intersection1_y, &intersection2_x, &intersection2_y)) {
        gdImageFilledEllipse(img, (int)intersection1_x, (int)intersection1_y, 5, 5, 0xFFFFFF);
        gdImageFilledEllipse(img, (int)intersection2_x, (int)intersection2_y, 5, 5, 0xFFFFFF);
    }

    if (circleLineIntersection(center_x, center_y, sun_radius, bx, by, ex, ey, &intersection1_x, &intersection1_y, &intersection2_x, &intersection2_y)) {
        gdImageFilledEllipse(img, (int)intersection1_x, (int)intersection1_y, 5, 5, 0xFFFFFF);
        gdImageFilledEllipse(img, (int)intersection2_x, (int)intersection2_y, 5, 5, 0xFFFFFF);
    }

    if (circleLineIntersection(center_x, center_y, sun_radius, ex, ey, dx, dy, &intersection1_x, &intersection1_y, &intersection2_x, &intersection2_y)) {
        gdImageFilledEllipse(img, (int)intersection1_x, (int)intersection1_y, 5, 5, 0xFFFFFF);
        gdImageFilledEllipse(img, (int)intersection2_x, (int)intersection2_y, 5, 5, 0xFFFFFF);
    }

    if (circleLineIntersection(center_x, center_y, sun_radius, dx, dy, ax, ay, &intersection1_x, &intersection1_y, &intersection2_x, &intersection2_y)) {
        gdImageFilledEllipse(img, (int)intersection1_x, (int)intersection1_y, 5, 5, 0xFFFFFF);
        gdImageFilledEllipse(img, (int)intersection2_x, (int)intersection2_y, 5, 5, 0xFFFFFF);
    }
}

int circleLineIntersection(float cx, float cy, float radius, float x1, float y1, float x2, float y2, float *intersection1_x, float *intersection1_y, float *intersection2_x, float *intersection2_y) {
    float dx, dy, A, B, C, det, t;

    dx = x2 - x1;
    dy = y2 - y1;

    A = dx * dx + dy * dy;
    B = 2 * (dx * (x1 - cx) + dy * (y1 - cy));
    C = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) - radius * radius;

    det = B * B - 4 * A * C;

    if ((A <= 0.00001) || (det < 0)) {
        // No real solutions.
        return 0;
    } else if (det == 0) {
        // One solution.
        t = -B / (2 * A);
        *intersection1_x = x1 + t * dx;
        *intersection1_y = y1 + t * dy;
        return 1;
    } else {
        // Two solutions.
        t = (-B + sqrt(det)) / (2 * A);
        *intersection1_x = x1 + t * dx;
        *intersection1_y = y1 + t * dy;

        t = (-B - sqrt(det)) / (2 * A);
        *intersection2_x = x1 + t * dx;
        *intersection2_y = y1 + t * dy;

        return 1;
    }
}
