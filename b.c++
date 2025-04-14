#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

void drawDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = dx / (float)steps, y_inc = dy / (float)steps;
    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_inc; y += y_inc;
    }
}

int main() {
    int gd = DETECT, gm, x1, y1, x2, y2;
    initgraph(&gd, &gm, "");
    for (int i = 1; i <= 8; i++) {
        printf("Line %d (x1 y1 x2 y2): ", i);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        drawDDA(x1, y1, x2, y2);
    }
    getch();
    closegraph();
    return 0;
}
