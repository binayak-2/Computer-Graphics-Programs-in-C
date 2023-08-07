#include<stdio.h>
#include<graphics.h>
#include<dos.h>
float round(float a);
void drawLineDDA(int x0, int y0, int x1, int y1){
	int dx=x1-x0;
	int dy=y1-y0;
	int steps, k;
	float xIncrement, yIncrement;
	float x=x0;
	float y=y0;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xIncrement=dx/(float)steps;
	yIncrement=dy/(float)steps;
	putpixel(round(x),round(y),WHITE);
	for(k=0;k<steps;k++)
		{
			x=x+xIncrement;
			y=y+yIncrement;
			putpixel(round(x),round(y),WHITE);
		}
}
int main(){
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"");
		
	int x0=50, y0=100;
	int x1=200, y1=250;
	drawLineDDA(x0, y0, x1, y1);
	delay(5000);
	closegraph();
}
float round(float a)
{
	int b=a+0.5;
	return b;
}