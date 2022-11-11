#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

void main(){
    int x[4], y[4], i;
    double put_x, put_y, u;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Please enter coordinates of 4 control points\n");
    for(i = 0; i < 4; i++){
        printf("C%d : ", i);
        scanf("%d%d", &x[i], &y[i]);
        putpixel(x[i], y[i], 3); 
    }
    
    setlinestyle(1, 0, 1);
    for(i=0 ; i<3 ; i++)
        line(x[i], y[i], x[i+1], y[i+1]);

	for (u = 0.0; u <= 1.0; u = u + 0.0001){
		put_x = pow(1-u, 3)*x[0] + 3*u*pow(1-u, 2)*x[1] + 3*pow(u, 2)*(1-u)*x[2] + pow(u, 3)*x[3];
        put_y = pow(1-u, 3)*y[0] + 3*u*pow(1-u, 2)*y[1] + 3*pow(u, 2)*(1-u)*y[2] + pow(u, 3)*y[3];
        putpixel(put_x, put_y, 7);
    }
    getch();
}