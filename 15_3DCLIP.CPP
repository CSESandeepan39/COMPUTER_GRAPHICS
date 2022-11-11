#include <iostream.h>
#include <graphics.h>
#include <conio.h>

const int INSIDE = 0, LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, NEAR = 16, FAR = 32;
const int Xmax = 400, Ymax = 350, Xmin = 200, Ymin = 150;

int findRCode(double x, double y){
	int code = INSIDE;
	if (x < Xmin) 
		code |= LEFT;
	else if (x > Xmax) 
		code |= RIGHT;
	if (y < Ymin) 
		code |= BOTTOM;
	else if (y > Ymax) 
		code |= TOP;
	return code;
}
void clipLine(double x1, double y1, double x2, double y2){
	int code1 = findRCode(x1, y1);
	int code2 = findRCode(x2, y2);
	int accept = 0;
    int code_out;
    double x, y;
	while (1) {
		if ((code1 == 0) && (code2 == 0)) {
			accept = 1;
			break;
		}
		else if (code1 & code2) break;
		else {
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			if (code_out & TOP) {
				x = x1 + (x2 - x1) * (Ymax - y1) / (y2 - y1);
				y = Ymax;
			}
			else if (code_out & BOTTOM) {
				x = x1 + (x2 - x1) * (Ymin - y1) / (y2 - y1);
				y = Ymin;
			}
			else if (code_out & RIGHT) {
				y = y1 + (y2 - y1) * (Xmax - x1) / (x2 - x1);
				x = Xmax;
			}
			else if (code_out & LEFT) {
				y = y1 + (y2 - y1) * (Xmin - x1) / (x2 - x1);
				x = Xmin;
			}

			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = findRCode(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = findRCode(x2, y2);
			}
		}
	}
	if (accept)
		line(x1, y1, x2, y2);
	else
		cout << "Line rejected" << endl;
}

void main(){
	int gd=DETECT, gm, x1, y1, z1, x2, y2, z2;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	setfillstyle(SOLID_FILL, BLACK);
	cout<<"Enter coordinates of 1st point of the line to be clipped : ";
	cin>>x1>>y1>>z1;
	cout<<"Enter coordinates of 2nd point of the line to be clipped : ";
	cin>>x2>>y2>>z2;
	bar3d(Xmin, Ymin, Xmax, Ymax, 50, 1);
	cout<<endl<<endl<<"Line Before Clipping.."<<endl;
	line(x1, y1, x2, y2);
	getch();
	cleardevice();
	bar3d(Xmin, Ymin, Xmax, Ymax, 50, 1);
	cout<<"Line After Clipping.."<<endl;
	clipLine(x1, y1, x2, y2);
	getch();
}