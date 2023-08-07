#include<stdio.h>
#include<graphics.h>
#include<dos.h>
int main()
{
	int gd=DETECT, gm;
	initgraph(&gm, &gd, "C:\\TurboC3\\Bgi");
	circle(100, 200, 50);
	getch();
}