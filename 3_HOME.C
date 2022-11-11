#include <graphics.h>
#include <conio.h>
void main(){
	int gm=DETECT, gd;
	initgraph(&gm, &gd, "C:\\TURBOC3\\BGI");
	rectangle(200, 240, 440, 360);
	rectangle(300, 270, 340, 360);
	line(200, 200, 440, 200);
	line(200, 200, 160, 240);
	line(440, 200, 480, 240);
	line(160, 240, 480, 240);
	line(300, 265, 340, 265);
	ellipse(320, 265, 0, 180, 20, 15);
	rectangle(235, 285, 265, 320);
	rectangle(375, 285, 405, 320);
	getch();
}