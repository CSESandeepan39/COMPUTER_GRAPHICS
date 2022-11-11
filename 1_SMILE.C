#include <graphics.h>
#include <conio.h>

void main(){
    int gm=DETECT, gd;
	initgraph(&gm, &gd, "C:\\TURBOC3\\BGI");
	circle(320, 240, 140);
	ellipse(320, 290, 195, 345, 70, 55);
	ellipse(320, 290, 200, 340, 70, 40);
	ellipse(250, 190, 0, 360, 10, 25);
	ellipse(390, 190, 0, 360, 10, 25);
	line(300, 285, 340, 285);
	line(320, 195, 300, 285);
	line(320, 195, 340, 285);
    getch();
}