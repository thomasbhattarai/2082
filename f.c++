#include <stdio.h>
#include <graphics.h>

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin=100, ymin=100, xmax=300, ymax=300;

int computeCode(double x, double y) {
    int c = INSIDE;
    if (x < xmin) c |= LEFT; else if (x > xmax) c |= RIGHT;
    if (y < ymin) c |= BOTTOM; else if (y > ymax) c |= TOP;
    return c;
}

void cohenSutherlandClip(double x1, double y1, double x2, double y2) {
    int c1=computeCode(x1,y1), c2=computeCode(x2,y2);
    while (1) {
        if (!(c1|c2)) { setcolor(GREEN); line(x1,y1,x2,y2); break; }
        else if (c1&c2) break;
        else {
            double x, y;
            int co = c1 ? c1 : c2;
            if (co&TOP) { x=x1+(x2-x1)*(ymax-y1)/(y2-y1); y=ymax; }
            else if (co&BOTTOM) { x=x1+(x2-x1)*(ymin-y1)/(y2-y1); y=ymin; }
            else if (co&RIGHT) { y=y1+(y2-y1)*(xmax-x1)/(x2-x1); x=xmax; }
            else { y=y1+(y2-y1)*(xmin-x1)/(x2-x1); x=xmin; }
            if (co==c1) { x1=x; y1=y; c1=computeCode(x1,y1); }
            else { x2=x; y2=y; c2=computeCode(x2,y2); }
        }
    }
}

int main() {
    double x1,y1,x2,y2;
    printf("Enter points (x1 y1 x2 y2): ");
    scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    int gd=DETECT,gm; initgraph(&gd,&gm,"");
    setcolor(WHITE); rectangle(xmin,ymin,xmax,ymax);
    setcolor(RED); line(x1,y1,x2,y2);
    cohenSutherlandClip(x1,y1,x2,y2);
    getch();
    closegraph();
    return 0;
}