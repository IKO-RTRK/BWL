#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../backend/src/bowling_stats.h"
#include "../frontend/src/bowling_gui.h"
#include "../frontend/src/traka.h"
#include "../backend/src/users.h"

// Primjer koristenja backend biblioteke
int main()
{
	system("clear");
	int8_t b;

	printf("Broj staza: ");
	scanf("%"SCNd8, &b);

	if (initialise(b))
	return 1;

	int8_t i, br, n, j;
	char name[50];
	for (i = 0; i < numberOfLanes; i++)
	{
		printf("Broja igraca na %d. stazi: ", i + 1);
		scanf("%"SCNd8, &n);
		if (createLane(i, n))
		{
			i--;	
		}
		else
		{
			for (j = 0; j < n; j++)
			{
				printf("Ime %d. igraca: ", j + 1);
				scanf("%s", name);
				if (createPlayer(i, name))
				{
					j--;
				}
			}
		}
	}

	system("clear");
	ShowTrack(allLanes , array);	

	return 0;
}

