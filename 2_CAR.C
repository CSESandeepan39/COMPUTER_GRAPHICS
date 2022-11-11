#include <graphics.h>
#include <conio.h>
void main(){
	int gm=DETECT, gd;
	initgraph(&gm, &gd, "C:\\TURBOC3\\BGI");
	line(200, 200, 440, 200);
	line(200, 200, 160, 250);
	line(440, 200, 480, 250);
	line(160, 250, 100, 250);
	line(480, 250, 540, 250);
	line(100, 250, 100, 290);
	line(540, 250, 540, 290);
	line(100, 290, 150, 290);
	line(490, 290, 540, 290);
	line(210, 290, 430, 290);
	circle(180, 290, 25);
	ellipse(180, 290, 0, 180, 30, 30);
	circle(460, 290, 25);
	ellipse(460, 290, 0, 180, 30, 30);
	getch();
}