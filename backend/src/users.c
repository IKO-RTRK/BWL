#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <ctype.h>
#include "users.h"


static int8_t numberOfLanesValidation(int8_t numberOfLanes)
{
	if (numberOfLanes < MIN_NUM_OF_LANES || numberOfLanes > MAX_NUM_OF_LANES)
		return 1;
	return 0;
}

static int8_t numberOfPlayersValidation(int8_t numberOfPlayers)
{
	if (numberOfPlayers < MIN_NUM_OF_PLAYERS || numberOfPlayers > MAX_NUM_OF_PLAYERS)
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

int8_t initialise(int8_t numOfLanes)
{	
	int8_t i;
	numberOfLanes = numOfLanes;
	int8_t valid = numberOfLanesValidation(numberOfLanes);	
		
	if (!valid)
	{
		allLanes = (lane*) calloc(numberOfLanes, sizeof(lane));		
	}
	else
	{
		printf("Broj staza koji ste unijeli nije validan!\n");
		return -1;
	}
	return 0;
}

int8_t createLane(int8_t laneId,int8_t numberOfPlayers)
{
	int8_t i;
	int8_t valid;			

	valid = numberOfPlayersValidation(numberOfPlayers);
				
	if (!valid)
	{
	 	allLanes[laneId].laneId = laneId;			
		allLanes[laneId].numberOfPlayers = 0;		
	 	allLanes[laneId].playersOnLane = (player*) calloc(numberOfPlayers, sizeof(player));
	}
	else
	{
	 	printf("Broj igraca 1-6 ! ");
	  	return -1;
	}
	return 0;
}

int8_t createPlayer(int8_t laneId, char* playerName)
{
	int8_t valid;	
	int8_t numberOfPlayers = allLanes[laneId].numberOfPlayers;
	
	valid = playerNameValidation(laneId,allLanes[laneId].numberOfPlayers,playerName);		
	
		if (!valid)
		{ 
			allLanes[laneId].playersOnLane[numberOfPlayers].name = (char*) malloc(strlen(playerName) + 1);
			strcpy(allLanes[laneId].playersOnLane[numberOfPlayers].name, playerName);
			allLanes[laneId].playersOnLane[numberOfPlayers].numOfThrow = NOT_EVALUATED;
			allLanes[laneId].playersOnLane[numberOfPlayers].totalScore = NOT_EVALUATED;
			int8_t i;
		
			for (i = 0; i < NUM_OF_FRAMES; i++)
				allLanes[laneId].playersOnLane[numberOfPlayers].frames[i] = NOT_EVALUATED;
		
			for (i = 0; i < MAX_NUM_OF_THROWS; i++)
				allLanes[laneId].playersOnLane[numberOfPlayers].points[i] = NOT_EVALUATED;
			allLanes[laneId].numberOfPlayers++;
		}
		else
		{
			printf("Uneseno ime vec postoji!\n");
			return -1;
		}
		return 0;
}
