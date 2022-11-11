// C Implementation for Flood Filling Algorithm
#include <graphics.h>
#include <conio.h>

void flood(int x, int y, int N, int O){
	if (getpixel(x, y) == O) {
		putpixel(x, y, N);
		flood(x+1, y, N, O);
		flood(x-1, y, N, O);
		flood(x, y+1, N, O);
		flood(x, y-1, N, O);
	}
}

void main(){
	int gd=DETECT, gm;
	int x = 250, y = 200, radius = 25;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	circle(x, y, radius);
	flood(x, y, GREEN, BLACK);
	getch();
}
