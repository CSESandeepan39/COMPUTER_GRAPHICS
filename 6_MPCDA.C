#include <graphics.h>
#include <conio.h>
#include <dos.h>
void main(){
	int gd=DETECT, gm, xc, yc, r, x, y, p;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	xc=200, yc=200;
	r=100;
	x=0, y=r;
	p=1-r;
	putpixel(xc+x, yc+y, WHITE);
	putpixel(xc+x, yc-y, WHITE);
	putpixel(xc-x, yc+y, WHITE);
	putpixel(xc-x, yc-y, WHITE);
	putpixel(xc+y, yc+x, WHITE);
	putpixel(xc+y, yc-x, WHITE);
	putpixel(xc-y, yc+x, WHITE);
	putpixel(xc-y, yc-x, WHITE);

	while(x<y){
		delay(20);
		x++;
		if(p<0)
			p += 2*x + 1;
		else{
			y--;
			p += 2*x + 1 - 2*y;
		}
		putpixel(xc+x, yc+y, WHITE);
		putpixel(xc+x, yc-y, WHITE);
		putpixel(xc-x, yc+y, WHITE);
		putpixel(xc-x, yc-y, WHITE);
		putpixel(xc+y, yc+x, WHITE);
		putpixel(xc+y, yc-x, WHITE);
		putpixel(xc-y, yc+x, WHITE);
		putpixel(xc-y, yc-x, WHITE);
	}
	getch();
}
