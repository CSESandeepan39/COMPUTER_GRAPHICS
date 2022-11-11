#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
}

void translation(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty){
	int x11, y11, x21, y21, x31, y31;
	x11 = x1 + tx;
	y11 = y1 + ty;
	x21 = x2 + tx;
	y21 = y2 + ty;
	x31 = x3 + tx;
	y31 = y3 + ty;
	drawTriangle(x11, y11, x21, y21, x31, y31);
}

void scalling(int x1, int y1, int x2, int y2, int x3, int y3, int sx, int sy){
	int x12, y12, x22, y22, x32, y32;
	x12 = x1 * sx;
	y12 = y1 * sy;
	x22 = x2 * sx;
	y22 = y2 * sy;
	x32 = x3 * sx;
	y32 = y3 * sy;
	drawTriangle(x12, y12, x22, y22, x32, y32);
}

void rotation(int x1, int y1, int x2, int y2, int x3, int y3, int theta){
	int x13, y13, x23, y23, x33, y33;
	float t = 3.14 * theta / 180;
	x13 = x1*cos(t) - y1*sin(t);
	y13 = x1*sin(t) + y1*cos(t);
	x23 = x2*cos(t) - y2*sin(t);
	y23 = x2*sin(t) + y2*cos(t);
	x33 = x3*cos(t) - y3*sin(t);
	y33 = x3*sin(t) + y3*cos(t);
	drawTriangle(x13, y13, x23, y23, x33, y33);
}

void shearing(int x1, int y1, int x2, int y2, int x3, int y3, int shx, int shy){
	int x14, y14, x24, y24, x34, y34;
	x14 = x1 + y1*shx;
	y14 = y1 + x1*shy;
	x24 = x2 + y2*shx;
	y24 = y2 + x2*shy;
	x34 = x3 + x3*shx;
	y34 = y3 + y3*shy;
	drawTriangle(x14, y14, x24, y24, x34, y34);
}

void main(){
	int gd=DETECT, gm;
	int x1, y1, x2, y2, x3, y3;
	int tx, ty, sx, sy, theta, shx, shy;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	x1 = 150, y1 = 50, x2 = 100, y2 = 100, x3 = 200, y3 = 100;
	tx = 50, ty = 60;
	sx = 3, sy = 2;
	theta = 45;
	shx = 2, shy = 2;

	drawTriangle(x1, y1, x2, y2, x3, y3);

	translation(x1, y1, x2, y2, x3, y3, tx, ty);
	scalling(x1, y1, x2, y2, x3, y3, sx, sy);
	rotation(x1, y1, x2, y2, x3, y3, theta);
	shearing(x1, y1, x2, y2, x3, y3, shx, shy);
	
	getch();
}