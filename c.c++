#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1, sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy, e2;

    while (1) {
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx)  { err += dx; y1 += sy; }
    }
}

int main() {
    int gd = DETECT, gm, lines[8][4];
    initgraph(&gd, &gm, "");

    printf("Enter 8 lines (x1 y1 x2 y2):\n");
    for (int i = 0; i < 8; i++) 
        scanf("%d %d %d %d", &lines[i][0], &lines[i][1], &lines[i][2], &lines[i][3]);

    for (int i = 0; i < 8; i++) 
        drawLine(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);

    getch();
    closegraph();
    return 0;
}
