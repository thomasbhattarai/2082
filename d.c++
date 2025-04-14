#include <graphics.h>
#include <iostream>
using namespace std;

void plot(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE); 
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE); 
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE); 
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE); 
    putpixel(xc - y, yc - x, WHITE);
}

void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r, P = 1 - r;
    while (x <= y) {
        plot(xc, yc, x++, y);
        P = (P < 0) ? P + 2 * x + 1 : P + 2 * (x - y--) + 1;
    }
}

int main() {
    int gd = DETECT, gm, xc, yc, r;
    initgraph(&gd, &gm, NULL);
    cout << "Enter center (xc yc) and radius: "; cin >> xc >> yc >> r;
    drawCircle(xc, yc, r);
    delay(5000000); 
    closegraph();
    return 0;
}
