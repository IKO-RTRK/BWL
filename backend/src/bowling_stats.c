#include "bowling_stats.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h

player** players;

static bool isSpare(uint8_t frameIndex) // helper funkcija za provjeru spare a
{/*
	return points[frameIndex] + points[frameIndex+1] == ALL_PINS_DOWN;
*/}

int8_t* get_points_array()
{
	/* points je organizovan na nacin:
	points[i*2] - vraca bodove sa prvog bacanja u i-tom frejmu
	points[i*2+1] - vraca bodove sa drugog bacanja u i-tom frejmu
	points[MAX_NUM_OF_THROWS-1] - vraca bodove sa dodatnog bacanja u zadnjem frejmu ( bitno provjeriti da li je stecen uslov za dodatno bacanje, ako nije ne treba ni ispisivati )
	bitno da znate kako bi kupili odgovarajuce bodove i ispisivali ih na ekran za odredjeni frejm
	*/
//	return points;
}
int16_t* get_frame_array()
{/*
	return frames;
*/}
 
int16_t score()
{/*
	uint8_t i; 
	uint8_t j = 0;
	for (i = 0; i < NUM_OF_FRAMES; i++)
	{
		if (points[j] == ALL_PINS_DOWN)            
		{	
			if(j < LAST_FRAME_FIRST_THROW)
			{
				if (points[j + 2] == ALL_PINS_DOWN)          //double
				{
					frames[i] = totalScore += (ALL_PINS_DOWN + points[j + 2] + points[j + 4]);
				}							
				else				//strike
				{
					frames[i] = totalScore += (ALL_PINS_DOWN + points[j + 2] + points[j + 3]);
				}
			}
			else
			{	
				frames[i] = totalScore += (ALL_PINS_DOWN + points[j + 1]+ points[j + 2]);// last frame different rules
			}
		}
		else if (isSpare(j) && (j <= LAST_FRAME_FIRST_THROW)) // spare
		{
			frames[i] = totalScore += (ALL_PINS_DOWN + points[j + 2]);
		}
		else
		{
			frames[i] = totalScore += (points[j] + points[j + 1]);
		}
		j += 2;

	}
	return totalScore;
*/}
						
void knockDown(uint8_t x)
{/*
	if (numOfThrow == MAX_NUM_OF_THROWS)
	{
		initialise();
	}	
	points[numOfThrow] = x;
	if ((x == ALL_PINS_DOWN) && (numOfThrow < LAST_FRAME_FIRST_THROW)) // last frame <=> different rules
	{
		points[++numOfThrow] = 0;  // ako je strike ima samo jedno bacanje u okviru => vazi za prvih devet frameova	
	}
	numOfThrow++;
*/}

static void initialise(int argc, char* argv[])
{ 
  uint8_t i, j = 2, k;
  int numberOfLanes = atoi(argv[1]);
  int numberOfPlayers[numberOfLanes];
  int totalNumberOfPlayers = 0;
  char* lanePlayers[6];
  players = (player**) malloc(sizeof(player*) * numberOfLanes);
  
  for (i = 0; i < numberOfLanes; i++)
  {
     numberOfPlayers[i] = atoi(argv[j]);
     //printf("1\n");
     
     for(k = 0; k < numberOfPlayers[i]; k++)
     {
       lanePlayers[k] = (char*) malloc(strlen(argv[++j])+1);
       strcpy(lanePlayers[k], argv[j]);
      }
     j++;
    
     
     
     players[i] = (player*) malloc (sizeof(player) * numberOfPlayers[i]);
     createLane(numberOfPlayers[i], players[i], &lanePlayers, i+1);
     //printf("2\n");
  }
  
  for (i = 0; i < numberOfLanes; i++)
  {
    for (j = 0; j < numberOfPlayers[i]; j++)
    {
      printf("%d\n", players[i][j].lane_id);
    }
  }
  
}

static void createPlayer(player* p, char nName[])
{
    p->name = (char*)calloc(strlen(nName) + 1, sizeof(char));
    strcpy(p->name, nName);
}


static void createLane(int num_of_players, player* heroes, char** names, int lane)
{
  uint8_t i;
  uint8_t j;
  uint8_t k;
     
    for (k=0; k < num_of_players; k++)
    {
	  createPlayer(heroes + k, names[k]);
	  
	  for(i = 0; i < NUM_OF_FRAMES; i++)
	  {
	      heroes[k].frames[i] = NOT_EVALUATED;
	  }
	  
	  

	  for(j = 0; j < MAX_NUM_OF_THROWS; j++)
	  {
	      heroes[k].points[j] = NOT_THROWN;
	  }
	  
	  heroes[k].lane_id = lane;
	  heroes[k].totalScore = 0;
	  heroes[k].numOfThrow = 0;
	  
    }
}

void testMemory(int* pointsCheck)
{/*
	uint8_t i = 0;
 	for (i = 0; i < 24; i++) 
	{
     		pointsCheck[i] = points[i];
  	}

*/}
