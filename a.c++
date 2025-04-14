#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    float x, y;
    printf("Enter the coordinates of x and y: ");
    scanf("%f %f", &x, &y);

    int xi = floor(x), yi = floor(y);
    fillellipse(xi, yi, 10, 10);

    printf("Scan Converted Point: (%d, %d)\n", xi, yi);

    getch();
    closegraph();
    return 0;
}
