#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

char IncFlag;
int PolygonPoints[3][2] = {{10, 100}, {110, 100}, {110, 200}};

void PolyLine() {
    int i;
    cleardevice();
    line(0, 240, 640, 240);
    line(320, 0, 320, 480);
    for (i = 0; i < 3; i++) {
        line(PolygonPoints[i][0], PolygonPoints[i][1], PolygonPoints[(i + 1) % 3][0], PolygonPoints[(i + 1) % 3][1]);
    }
}

void Reflect() {
    int i;
    // Move the triangle to the origin
    int minX = PolygonPoints[0][0];
    int minY = PolygonPoints[0][1];
    for (i = 1; i < 3; i++) {
        if (PolygonPoints[i][0] < minX) minX = PolygonPoints[i][0];
        if (PolygonPoints[i][1] < minY) minY = PolygonPoints[i][1];
    }

    for (i = 0; i < 3; i++) {
        PolygonPoints[i][0] -= minX;
        PolygonPoints[i][1] -= minY;
    }

    // Reflect the points across the x-axis
    for (i = 0; i < 3; i++) {
        PolygonPoints[i][1] = 480 - PolygonPoints[i][1];
    }

    // Move the triangle back to its original position
    for (i = 0; i < 3; i++) {
        PolygonPoints[i][0] += minX;
        PolygonPoints[i][1] += minY;
    }
}

int main() {
    int gd = DETECT, gm;
    int i;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    for (i = 0; i < 3; i++) {
        PolygonPoints[i][0] += 320;
        PolygonPoints[i][1] = 240 - PolygonPoints[i][1];
    }

    PolyLine();
    getch();

    Reflect();
    PolyLine();
    getch();
    closegraph();
    return 0;
}