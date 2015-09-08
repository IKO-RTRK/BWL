#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../src/bowling_stats.h"
#include "../src/users.h"

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
	initialise(3);
	int8_t i, br, n, j;
	char name[50];
	for (i = 0; i < numberOfLanes; i++)
	{
		printf("Broja igraca na %d. stazi: ", i + 1);
		scanf("%"SCNd8, &n);
		if (createLane(i, n))
		{
			printf("Broj igraca od 1 do 6!\n");
			i--;	
		}
	}

	for (i = 0; i < numberOfLanes; i++)
	{
		printf("%d. staza: \n", i + 1);
		for (j = 0; j < allLanes[i].numberOfPlayers; j++)
		{
			printf("Ime %d. igraca: ", j + 1);
			scanf("%s", name);
			createPlayer(i, name);
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


	return 0;
}

