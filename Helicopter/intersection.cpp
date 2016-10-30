#include "header.h"

void crosspoint(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double *crossX, double *crossY)
{
	*crossX = -((x1*y2 - x2*y1)*(x4 - x3) - (x3*y4 - x4*y3)*(x2 - x1)) / ((y1 - y2)*(x4 - x3) - (y3 - y4)*(x2 - x1));
	*crossY = ((y3 - y4)*(-(*crossX)) - (x3*y4 - x4*y3)) / (x4 - x3);
}

double direction(double pix, double piy, double pjx, double pjy, double pkx, double pky)
{
	return ((pkx - pix)*(pjy - piy) - (pjx - pix)*(pky - piy));
}

void intersection(vector <Points> v)
{
	double crossX, crossY, x1, y1, x2, y2, x3, y3, x4, y4;
	double d1, d2, d3, d4;
	int crossFlag = 0;

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size() - 1; j++) {

			x1 = v[i].x;
			y1 = v[i].y;
			x2 = v[i + 1].x;
			y2 = v[i + 1].y;
			x3 = v[j].x;
			y3 = v[j].y;
			x4 = v[j + 1].x;
			y4 = v[j + 1].y;

			d1 = direction(x3, y3, x4, y4, x1, y1);
			d2 = direction(x3, y3, x4, y4, x2, y2);
			d3 = direction(x1, y1, x2, y2, x3, y3);
			d4 = direction(x1, y1, x2, y2, x4, y4);

			if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
				crosspoint(x1, y1, x2, y2, x3, y3, x4, y4, &crossX, &crossY);

				printf("Coordinates: (%.3f, %.3f)\n", crossX, crossY);
				printf("Intersecting lines: %d-%d, %d-%d\n", i, i + 1, j, j + 1);
				crossFlag++;
			}
		}
	}

	if (crossFlag == 0) {
		printf("Intersection not found.\n");
		exit(1);
	}
}