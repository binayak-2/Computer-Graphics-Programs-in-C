/*** Program to Draw an Ellipse using Mid - Point Algorithm ***/

#include <stdio.h>
#include <graphics.h>

void ellipseMidpoint(int, int, int, int);
void drawEllipse(int, int, int, int);

int main()
{
    int xc, yc, rx, ry;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    printf("\nEnter the center coordinates of ellipse: ");
    scanf("%d %d", &xc, &yc);
    printf("\nEnter x-radius coordinate: ");
    scanf("%d", &rx);
    printf("\nEnter y-radius coordiante: ");
    scanf("%d", &ry);

    ellipseMidpoint(xc, yc, rx, ry);

    getch();
}

void ellipseMidpoint(int xc, int yc, int rx, int ry)
{
    int rxSq = rx * rx;
    int rySq = ry * ry;
    int x = 0, y = ry;
    int p;
    int px = 0, py = 2 * rxSq * y;
    drawEllipse(xc, yc, x, y);

    // Region 1
    p = rySq - (rxSq * ry) + (0.25 * rxSq);

    while (px < py)
    {
        x++;
        px = px + 2 * rySq;

        if (p < 0)
            p = p + rySq + px;
        else
        {
            y--;
            py = py - 2 * rxSq;
            p = p + rySq + px - py;
        }

        drawEllipse(xc, yc, x, y);
        delay(30);
    }

    // Region 2
    p = rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq;

    while (y > 0)
    {
        y--;
        py = py - 2 * rxSq;

        if (p > 0)
            p = p + rxSq - py;
        else
        {
            x++;
            px = px + 2 * rySq;
            p = p + rxSq - py + px;
        }

        drawEllipse(xc, yc, x, y);
        delay(30);
    }
}

void drawEllipse(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}
