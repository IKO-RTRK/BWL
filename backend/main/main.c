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
	initialise();

	baci();

	printf("Total: %" PRIu16"\n", allLanes[0].playersOnLane[0].totalScore);

	int i;

	for (i = 0; i < MAX_NUM_OF_THROWS; i++)
	printf("%"PRId8" ", allLanes[0].playersOnLane[0].points[i]);

	printf("\n");

	for (i = 0; i < NUM_OF_FRAMES; i++)
	printf("%"PRId8" ", allLanes[0].playersOnLane[0].frames[i]);
	printf("\n");


	return 0;
}

