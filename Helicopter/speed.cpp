#include "header.h"

void speed(vector <Time> v, vector <Points> v1) 
{
	double length = 0;
	double speed = 0;
	int size = v.size();
	vector <int> minute(size);

	printf("The average speed on each stage:\n\n");

	for (int i = 1; i < size; i++)
	{
		if (v[i].hour - v[i - 1].hour == -23)
			minute[i - 1] = (((v[i].hour + 24) * 60 + v[i].minute) - (v[i - 1].hour * 60 + v[i - 1].minute)) - 5;
		else
			minute[i - 1] = ((v[i].hour * 60 + v[i].minute) - (v[i - 1].hour * 60 + v[i - 1].minute)) - 5;

		if ((minute[i - 1] <= 0)) {
			printf("Logical-time error.\n");
			exit(1);
		}
		else {
			length = sqrt(pow(v1[i - 1].x - v1[i].x, 2) + pow(v1[i - 1].y - v1[i].y, 2));

			speed = length / minute[i - 1];
			printf("%d.Distance: %.3f; Speed: %.3f\n", i, length, speed);
		}
	}
}