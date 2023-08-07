#include <stdio.h>
#include <graphics.h>

int main()
{
	int x1, y1, x2, y2, tx, ty;
	int x3, y3, x4, y4;
	
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
    
    printf("Enter x1 and y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter x2 and y2: ");
    scanf("%d%d", &x2, &y2);
    printf("Enter translation distances: ");
    scanf("%d%d", &tx, &ty);
    
    setcolor(5);
    line(x1, y1, x2, y2);
    outtextxy(x2+2, y2+2, "Original line");
    
    x3=x1+tx;
    y3=y1+ty;
    x4=x2+tx;
    y4=y2+ty;
    
    setcolor(7);
    line(x3, y3, x4, y4);
    outtextxy(x4+2, y4+2, "Line after translation");
    getch();
    
    
    
}