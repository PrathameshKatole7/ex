#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

class LineDrawer {
    float x, y, dx, dy, xi, yi;
    int steps;

public:
    void lin(int x1, int y1, int x2, int y2) {
        dx = x2 - x1;
        dy = y2 - y1;

        if (abs(dx) > abs(dy))
            steps = abs(dx);
        else
            steps = abs(dy);

        xi = dx / (float)steps;
        yi = dy / (float)steps;

        x = x1 + 0.5f;
        y = y1 + 0.5f;

        putpixel(round(x), round(y), 9);

        for (int i = 1; i <= steps; i++) {
            x += xi;
            y += yi;
            putpixel(round(x), round(y), 9);
            delay(2);
        }
    }
} l;

class CircleDrawer {
    void plotPoints(int xc, int yc, int x, int y) {
        putpixel(xc + x, yc + y, 3);
        putpixel(xc - x, yc + y, 3);
        putpixel(xc + x, yc - y, 3);
        putpixel(xc - x, yc - y, 3);
        putpixel(xc + y, yc + x, 3);
        putpixel(xc - y, yc + x, 3);
        putpixel(xc + y, yc - x, 3);
        putpixel(xc - y, yc - x, 3);
    }

public:
    void drawCircle(int xc, int yc, int rad) {
        int x1 = 0;
        int y1 = rad;
        int pk = 3 - 2 * rad;

        plotPoints(xc, yc, x1, y1);

        while (x1 <= y1) {
            if (pk <= 0) {
                pk = pk + (4 * x1) + 6;
            } else {
                pk = pk + 4 * (x1 - y1) + 10;
                y1--;
            }
            x1++;
            plotPoints(xc, yc, x1, y1);
            delay(5);
        }
    }
} c;

int main() {
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, NULL);

    // Outer Rectangle / Square
    l.lin(100, 100, 400, 100);
    l.lin(100, 400, 400, 400);
    l.lin(100, 100, 100, 400);
    l.lin(400, 100, 400, 400);

    // Inscribed Diamond / Rhombus
    l.lin(250, 100, 100, 250);
    l.lin(100, 250, 250, 400);
    l.lin(250, 100, 400, 250);
    l.lin(400, 250, 250, 400);

    // Inscribed Circle (radius ~106 touches the diamond edges)
    c.drawCircle(250, 250, 106);

    delay(3000);
    closegraph();
    return 0;
}
