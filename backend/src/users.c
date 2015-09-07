#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
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

int playerNameValidation(int8_t laneId,int8_t position,char* newName)
{
	int8_t i;
	
	for(i = 0; i < position; i++)
	{
		if (!strcmp(allLanes[laneId].playersOnLane[i].name,newName))
			return 1;
	}
	return 0;
}

void initialise()
{
	int8_t numberOfLanes;
	int8_t i;
	
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
	int8_t i;
	
	printf("Staza %d:\n", laneId);
	printf("Koliko igraca ce igrati na stazi: ");			//unos broja igraca na stazi
	scanf("%" SCNd8, &numberOfPlayers);
	int valid = numberOfPlayersValidation(numberOfPlayers);		//provjera validnosti

	if (!valid)
	{
		allLanes[laneId].laneId = laneId;			//dodan Id staze
		allLanes[laneId].numberOfPlayers = numberOfPlayers;		//dodan broj igraca
		allLanes[laneId].playersOnLane = calloc (numberOfPlayers, sizeof(player));
		for (i = 0; i < numberOfPlayers; i++)
		{
			createPlayer(laneId,i);					//kreiranje igraca
		}
	}
}

void createPlayer(int8_t laneId,int8_t position)
{
	int valid = 1;
	while(valid)				// petlja omogucava da se ponovi unos, ako prethodni nije validan
	{
		char tmp[200];
		printf("Igrac %d\n", position+1);
		printf("Unesi ime igraca: " );
		scanf("%s", tmp);						// unos imena igraca
		valid = playerNameValidation(laneId,position,tmp)		//provjera validnosti imena
	
		if (!valid)
		{																				// inicijalizacija podataka igraca
			allLanes[laneId].playersOnLane[position].name =(char*) malloc(strlen(tmp) + 1);
			strcpy(allLanes[laneId].playersOnLane[position].name,tmp);
			allLanes[laneId].playersOnLane[position].numOfThrow = NOT_EVALUATED;
			allLanes[laneId].playersOnLane[position].totalScore = NOT_EVALUATED;
			int i;
		
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