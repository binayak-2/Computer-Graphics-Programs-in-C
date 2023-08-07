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
    for (i = 0; i < 3; i++) {
        PolygonPoints[i][0] = (640 - PolygonPoints[i][0]);
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