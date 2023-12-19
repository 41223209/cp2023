#include <stdio.h>
#include <gd.h>
#include <math.h>

#define M_PI 3.14159265358979323846

void draw_korea_flag(gdImagePtr img);
void draw_redandblue_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int white, int red, int blue, int grey);
void drawRotatedFilledRectangle(gdImagePtr img, double gossip_width, double gossip_height, double angle, int grey)

int main() {
    // width 3: height 2
    int width = 720;
    int height = (int)(width*2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_korea_flag(img);

    FILE *outputFile = fopen("./korea_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_korea_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue, grey;
    int center_x = (int)(width/2);
    int center_y = (int)(height/2);
    int sun_radius = (int)(width/3);

    // Colors for the flag
    red = gdImageColorAllocate(img, 242, 0, 0); // Red color
    white = gdImageColorAllocate(img, 255, 255, 255); // White stripes
    blue = gdImageColorAllocate(img, 0, 41, 204);
    grey = gdImageColorAllocate(img, 1, 1, 1);

    // 繪製白色矩形區域
    gdImageFilledRectangle(img, 0, 0, width, height, white);

    // 繪製太陽
    gdImageFilledArc(img, center_x, center_y, sun_radius * 1, sun_radius * 1, 214, 56, red, gdArc);

   gdImageFilledArc(img, center_x, center_y, sun_radius * 1, sun_radius * 1, 34, 214, blue, gdArc);

  gdImageFilledEllipse(img, 310.5, 208.1, sun_radius * 1/2, sun_radius * 1/2, red);

  gdImageFilledEllipse(img, 409.9230177, 273.2820118, sun_radius * 1/2, sun_radius * 1/2, blue);
  
      double angleRadians = angle * M_PI / 180.0;

      double x1 = 0, y1 = 0;
      double x2 = gossip_width, y2 = 0;
      double x3 = gossip_width, y3 = gossip_height;
      double x4 = 0, y4 = gossip_height;

      double rotatedX1 = x1 * cos(angleRadians) - y1 * sin(angleRadians);
      double rotatedY1 = x1 * sin(angleRadians) + y1 * cos(angleRadians);

      double rotatedX2 = x2 * cos(angleRadians) - y2 * sin(angleRadians);
      double rotatedY2 = x2 * sin(angleRadians) + y2 * cos(angleRadians);

      double rotatedX3 = x3 * cos(angleRadians) - y3 * sin(angleRadians);
      double rotatedY3 = x3 * sin(angleRadians) + y3 * cos(angleRadians);

      double rotatedX4 = x4 * cos(angleRadians) - y4 * sin(angleRadians);
      double rotatedY4 = x4 * sin(angleRadians) + y4 * cos(angleRadians);

      gdImageFilledPolygon(img, (int[]){rotatedX1, rotatedX2, rotatedX3, rotatedX4},
                           (int[]){rotatedY1, rotatedY2, rotatedY3, rotatedY4}, 4, grey);

   double gossip_width = 120.0;
   double gossip_height = 00.0;

  // 创建一个 width x height 的图像
   (gdImagePtr img)= gdImageCreate((int)gossip_width, (int)gossip_height);

  // 设置矩形的颜色
   int fillColor = gdImageColorAllocate(img, 0, 0, 0);

  // 旋转角度
   double angle = 34.0;

  // 调用函数绘制填充矩形
   drawRotatedFilledRectangle(img, gossip_width, gossip_height, angle, grey);
 }