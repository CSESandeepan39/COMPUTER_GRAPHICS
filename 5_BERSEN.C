#include <graphics.h>
#include <conio.h>
//#include <dos.h>

void main(){
	int gd=DETECT, gm, x0, x1, y0, y1, x, y, dx, dy, p;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	//x0 = 100, y0 = 50;
	//x1 = 450, y1 = 300;
	printf("Enter the coordinates of first end point : ");
	scanf("%d %d", &x0, &y0);
	printf("Enter the coordinates of second end point : ");
	scanf("%d %d", &x1, &y1);
	dx = x1-x0;
	dy = y1-y0;
	x = x0, y = y0;
	p = 2*dy - dx;
	while(x < x1){
		if(p<0){
			putpixel(x, y, WHITE);
			p += 2*dy;
		}
		else{
			putpixel(x, y, WHITE);
			p += 2*dy - 2*dx;
			y++;
		}
		x++;
		//delay(20);
	}
	getch();
}