#include "header.h"

void getCycles(vector <Points> loc)
{
	int cycle = 0;
	for (unsigned int i = 0; i < loc.size(); i++)
	{
		for (unsigned int j = 1; j < loc.size(); j++)
		{
			if ((loc[i].x == loc[j].x) && (loc[i].y == loc[j].y) && (i < j))
			{
				printf("Tops cycle: %d - %d\n", i, j);

				for (unsigned int k = i; k <= j; k++) {
					printf("%.3f, %.3f\n", loc[k].x, loc[k].y);
				}

				cycle++;
				i = j;
			}

		}
	}

	if (cycle)
		printf("Count cycle: %d\n", cycle);
	else
		printf("Cycles not found.\n");
}