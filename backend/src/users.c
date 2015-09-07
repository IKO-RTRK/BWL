#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "users.h"


int numberOfLanesValidation(int numberOfLanes)
{
	if (numberOfLanes < 1 || numberOfLanes > 3)
		return 1;
	return 0;
}

int numberOfPlayersValidation(int numberOfPlayers)
{
	if (numberOfPlayers < 1 || numberOfPlayers > 6)
		return 1;
	return 0;
}

void initialise()
{
	int8_t numberOfLanes;
	int i;
	
	printf("Koliko staza zelite kreirati: ");		//unos broja staza
	scanf("%" SCNd8, &numberOfLanes);
	int valid = numberOfLanesValidation(numberOfLanes);		//provjera unosa
		
	if (!valid)
	{
		allLanes = (lane*) calloc(numberOfLanes, sizeof(lane));		//alokacija niza staza
		for (i = 0; i < numberOfLanes; i++)
		{			
			createLane(i);						//kreiranje staze
		}
	}
	else
	{
		printf("Broj traka koji ste unijeli nije validan!\n");
	}
}

void createLane(int8_t laneId)
{
	int8_t numberOfPlayers;
	int i;
	
	printf("Staza %d:\n", laneId);
	printf("Koliko igraca ce igrati na stazi: ");			//unos broja igraca na stazi
	scanf("%" SCNd8, &numberOfPlayers);
	int valid = numberOfPlayersValidation(numberOfPlayers);		//provjera validnosti

	if (!valid)
	{
		allLanes[laneId].laneId = laneId;			//dodan Id staze
		allLanes[laneId].numberOfPlayers = numberOfPlayers;		//dodan broj igraca
		for (i = 0; i < numberOfPlayers; i++)
		{
			//createPlayer();					//kreiranje igraca
		}
	}
}

void createPlayer(int8_t laneId)
{
	
}