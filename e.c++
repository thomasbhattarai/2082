#include <stdio.h>
#include <graphics.h>

int main() {
    int Xmin, Xmax, Ymin, Ymax;
    int x, y;

    // Taking input for the clipping window
    printf("Enter the clipping window boundaries (Xmin Xmax Ymin Ymax): ");
    scanf("%d %d %d %d", &Xmin, &Xmax, &Ymin, &Ymax);

    // Taking input for the point
    printf("Enter the coordinates of the point (x y): ");
    scanf("%d %d", &x, &y);

    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw the clipping window
    rectangle(Xmin, Ymin, Xmax, Ymax);

    // Draw the point
    if (x > Xmin && x < Xmax && y > Ymin && y < Ymax) {
        setcolor(WHITE);
        outtextxy(20, 20, "Point is inside the clipping window.");
    } else {
        setcolor(WHITE);
        outtextxy(20, 20, "Point is outside the clipping window.");
    }

    // Display the point as a small circle
    setcolor(WHITE);
    circle(x, y, 3);
    floodfill(x, y, WHITE);

    getch(); // Wait for user to press a key
    closegraph(); // Close the graphics window

    return 0;
}