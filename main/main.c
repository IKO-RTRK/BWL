#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../backend/src/bowling_stats.h"
#include "../frontend/src/bowling_gui.h"
#include "../backend/src/users.h"

void baci()
{
	knockDown(&allLanes[0].playersOnLane[0], 1);
	knockDown(&allLanes[0].playersOnLane[0], 4);
	knockDown(&allLanes[0].playersOnLane[0], 4);
	knockDown(&allLanes[0].playersOnLane[0], 5);
	knockDown(&allLanes[0].playersOnLane[0], 6);
	knockDown(&allLanes[0].playersOnLane[0], 4);
	knockDown(&allLanes[0].playersOnLane[0], 5);
	knockDown(&allLanes[0].playersOnLane[0], 5);
	knockDown(&allLanes[0].playersOnLane[0], 10);
	knockDown(&allLanes[0].playersOnLane[0], 0);
	knockDown(&allLanes[0].playersOnLane[0], 1);
	knockDown(&allLanes[0].playersOnLane[0], 7);
	knockDown(&allLanes[0].playersOnLane[0], 3);
	knockDown(&allLanes[0].playersOnLane[0], 6);
	knockDown(&allLanes[0].playersOnLane[0], 4);
	knockDown(&allLanes[0].playersOnLane[0], 10);
	knockDown(&allLanes[0].playersOnLane[0], 2);
	knockDown(&allLanes[0].playersOnLane[0], 8);
	knockDown(&allLanes[0].playersOnLane[0], 6);
}

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

	baci();

	printf("Total: %" PRIu16"\n", allLanes[0].playersOnLane[0].totalScore);

	

	for (i = 0; i < MAX_NUM_OF_THROWS; i++)
	printf("%"PRId8" ", allLanes[0].playersOnLane[0].points[i]);

	printf("\n");

	for (i = 0; i < NUM_OF_FRAMES; i++)
	printf("%"PRId8" ", allLanes[0].playersOnLane[0].frames[i]);
	printf("\n");
	system("clear");
	initialisationTrack();
	initialisationTable();
	print();
	return 0;
}

