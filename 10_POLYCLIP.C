#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int gd=DETECT, gm, n, *x, i, k = 0;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // initializing graphics
	setcolor(RED);							 // red colored window
	rectangle(150, 150, 490, 330);
	printf("Enter the no. of vertices of polygon: ");
	scanf("%d", &n);
	x = malloc(n * 2 + 1);
	printf("Enter the coordinates of points:\n");
	for (i = 0; i < n * 2; i += 2){
		printf("(x%d,y%d): ", k, k);
		scanf("%d %d", &x[i], &x[i + 1]);
		k++;
	}
	x[n * 2] = x[0]; // assigning the coordinates of first vertex to last additional vertex for drawpoly method.
	x[n * 2 + 1] = x[1];
	setcolor(WHITE);
	drawpoly(n + 1, x);
	printf("\nPress a button to clip a polygon..");
	getch();
	setcolor(RED);
	rectangle(150, 150, 490, 330);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(2, 2, RED);
	gotoxy(1, 1); // bringing cursor at starting position
	printf("\nThis is the clipped polygon..");
	getch();
	return 0;
}