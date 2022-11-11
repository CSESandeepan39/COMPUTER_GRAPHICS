// C Implementation for Boundary Filling Algorithm
#include <graphics.h>
#include <conio.h>

void boundary(int x, int y, int F, int B){
	if(getpixel(x, y) != B && getpixel(x, y) != F){
		putpixel(x, y, F);
		boundary(x+1, y, F, B);
		boundary(x, y+1, F, B);
		boundary(x-1, y, F, B);
		boundary(x, y-1, F, B);
    }
}

void main(){
	int gd=DETECT, gm;
	int x = 250, y = 200, radius = 25;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	circle(x, y, radius);
	boundary(x, y, GREEN, WHITE);
	getch();
}
