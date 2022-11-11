#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

void main(){
	int gd=DETECT, gm, xc, yc, rx, ry, x, y;
	float p1, p2;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	xc = 200, yc = 200;
	rx = 150, ry = 100;
	x = 0, y = ry;
	p1 = pow(ry, 2) - pow(rx, 2)*ry + 0.25*pow(rx, 2);
	putpixel(xc+x, yc+y, 7);
	putpixel(xc+x, yc-y, 7);
	putpixel(xc-x, yc+y, 7);
	putpixel(xc-x, yc-y, 7);
	while(2*pow(ry, 2)*x < 2*pow(rx, 2)*y){
		x++;
		if(p1<0)
			p1 += 2*pow(ry, 2)*x + pow(ry, 2);
		else{
			y--;
			p1 += 2*pow(ry, 2)*x + pow(ry, 2) - 2*pow(rx, 2)*y;
		}
		putpixel(xc+x, yc+y, 7);
		putpixel(xc+x, yc-y, 7);
		putpixel(xc-x, yc+y, 7);
		putpixel(xc-x, yc-y, 7);
		delay(10);
	}
	p2 =  pow(ry, 2)*pow(x+0.5, 2) + pow(rx, 2)*pow(y-1, 2) - pow(rx*ry, 2);
	while(x <= rx && y >= 0){
		y--;
		if(p2>0)
			p2 += pow(rx, 2) - 2*pow(rx, 2)*y;
		else{
			x++;
			p2 += 2*pow(ry, 2)*x + pow(rx, 2) - 2*pow(rx, 2)*y;
		}
		putpixel(xc+x, yc+y, 7);
		putpixel(xc+x, yc-y, 7);
		putpixel(xc-x, yc+y, 7);
		putpixel(xc-x, yc-y, 7);
		delay(10);
	}
	getch();
}
