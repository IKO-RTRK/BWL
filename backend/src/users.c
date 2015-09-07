#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "users.h"


static int8_t numberOfLanesValidation()
{
	if (numberOfLanes < 1 || numberOfLanes > 3)
		return 1;
	return 0;
}

static int8_t numberOfPlayersValidation(int8_t numberOfPlayers)
{
	if (numberOfPlayers < 1 || numberOfPlayers > 6)
		return 1;
	return 0;
}

static int8_t playerNameValidation(int8_t laneId, int8_t position, char* newName)
{
	int8_t i;
	
	for(i = 0; i < position; i++)
	{
		if (!strcmp(allLanes[laneId].playersOnLane[i].name, newName))
			return 1;
	}
	return 0;
}

void initialise()
{
	int8_t i;
	
	printf("Koliko staza zelite kreirati: ");		
	scanf("%" SCNd8, &numberOfLanes);
	int8_t valid = numberOfLanesValidation(numberOfLanes);		
		
	if (!valid)
	{
		allLanes = (lane*) calloc(numberOfLanes, sizeof(lane));		
		for (i = 0; i < numberOfLanes; i++)
		{			
			createLane(i);					
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
	int8_t i;
	int8_t valid = 1;
	
	printf("Staza %d:\n", laneId + 1);
	printf("Koliko igraca ce igrati na stazi: ");			

	while (valid)
	{
		scanf("%" SCNd8, &numberOfPlayers);
		valid = numberOfPlayersValidation(numberOfPlayers);
		if (valid)
			printf("Broj igraca 1-6 ! Unesite ponovo: ");
	}		
	
	allLanes[laneId].laneId = laneId;			
	allLanes[laneId].numberOfPlayers = numberOfPlayers;		
	allLanes[laneId].playersOnLane = (player*) calloc(numberOfPlayers, sizeof(player));
	for (i = 0; i < numberOfPlayers; i++)
	{
		createPlayer(laneId, i);					
	}
}

void createPlayer(int8_t laneId, int8_t position)
{
	int8_t valid = 1;
	while(valid)				
	{
		char tmp[200];
		printf("Unesite ime %d. igraca: ", position + 1);
		scanf("%s", tmp);					
		valid = playerNameValidation(laneId,position,tmp);		
	
		if (!valid)
		{ 
			allLanes[laneId].playersOnLane[position].name = (char*) malloc(strlen(tmp) + 1);
			strcpy(allLanes[laneId].playersOnLane[position].name, tmp);
			allLanes[laneId].playersOnLane[position].numOfThrow = NOT_EVALUATED;
			allLanes[laneId].playersOnLane[position].totalScore = NOT_EVALUATED;
			int8_t i;
		
			for (i = 0; i < NUM_OF_FRAMES; i++)
				allLanes[laneId].playersOnLane[position].frames[i] = NOT_EVALUATED;
		
			for (i = 0; i < MAX_NUM_OF_THROWS; i++)
				allLanes[laneId].playersOnLane[position].points[i] = NOT_EVALUATED;
		}
		else
		{
			printf("Uneseno ime vec postoji!\n");
		}
	}
}
