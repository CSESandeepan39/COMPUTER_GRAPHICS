#include <graphics.h>
#include <conio.h>
//#include <dos.h>

void main(){
	int gd=DETECT, gm, i, x0, x1, y0, y1;
	float x, y, dx, dy, steps;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the coordinates of first end point : ");
	scanf("%d %d", &x0, &y0);
	printf("Enter the coordinates of second end point : ");
	scanf("%d %d", &x1, &y1);
	//x0 = 100, y0 = 100,	x1 = 400, y1 = 400;
	dx = (float)(x1-x0);
	dy = (float)(y1-y0);
	if(dx>=dy) steps = dx;
	else steps = dy;
	dx = dx/steps;
	dy = dy/steps;
	x = x0, y = y0;
	for(i=1 ; i<=steps ; i++){
		putpixel(x, y, WHITE);
		x += dx;
		y += dy;
		//delay(20);
	}
	getch();
}