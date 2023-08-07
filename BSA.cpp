#include<stdio.h>
#include<graphics.h>

int main()
{
	int x, y, x1, y1;
	int x2, y2, p, dx, dy;
	
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	
//	printf("Enter x1 and y1: ");
//	scanf("%d%d", &x1, &y1);
//	printf("Enter x2 and y2: ");
//	scanf("%d%d", &x2, y2);

	x1=100;
	x2=200;
	y1=200;
	y2=300;
	
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;
	
	putpixel(x, y, 2);
	p=(2*dy-dx);
	
	while(x<=x2)
	{
		if(p<0)
		{
			x=x+1;
			p=p+2*dy;
		}
		else
		{
			x=x+1;
			y=y+1;
			p=p+(2*dy)-(2*dx);
		}
		putpixel(x, y, 7);
	}
	getch();
	
}