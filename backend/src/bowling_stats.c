#include "bowling_stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>

player** players;
int numberOfLanes;
int* numberOfPlayers;
int* laneIds;

static int validate(int argc,char* argv[])
{
	uint8_t i, j = 2, k, l, numLanes, numPlayersByLanes[numLanes];
	
	if(argc < 4)
	{
		return 1;	//premalo parametara
	}

	if(!isdigit(atoi(argv[1])))
	{
		numLanes=atoi(argv[1]);	
	}
	else
		return 1;	// nije broj

	if(numLanes > 3)
	{
		return 1;	//previse staza
	}

	if(numLanes >= 1)
	{

		if(!isdigit(atoi(argv[j])))
		{
			numPlayersByLanes[0]=atoi(argv[j]);
		}
		else
			return 1;	// nije broj

		if(numPlayersByLanes[0] > 6)
		{
			return 1;	//previse igraca po stazi
		}

		if(numLanes>=2)
		{

			if(!isdigit(atoi(argv[j+numPlayersByLanes[0]+1])))
			{
				numPlayersByLanes[1]=atoi(argv[j+numPlayersByLanes[0]+1]);
			}
			else
				return 1;	// nije broj

			if(numPlayersByLanes[1]>6)
			{
				return 1;	//previse igraca po stazi
			}

			if(numLanes==3)
			{
				if(!isdigit(atoi(argv[j+numPlayersByLanes[0]+numPlayersByLanes[1]+1])))
				{
					numPlayersByLanes[2]=atoi(argv[j+numPlayersByLanes[0]+numPlayersByLanes[1]+2]);
				}
				else
					return 1;	// nije broj

				if(numPlayersByLanes[2]>6)
				{
					return 1;	//previse igraca po stazi
				}
			}
		}	
	}
	
	char* namesLane[3][6];
	
	for(l=0;l<3;l++)
	{
	
		for(i=0;i<numPlayersByLanes[l];i++)
		{
			namesLane[l][i] = (char*) malloc(strlen(argv[++j])+1);
       			strcpy(namesLane[l][i], argv[j]);
			for(k=0;k<i;k++)
			{
				if(strcmp(namesLane[l][i],namesLane[l][k])==0)
				{
					return 1;
				}	
			}
			j++;
		}
	}
//***Napomena: Nije provjereno da li ima dovoljno igraca po stazama i da li ima dovoljno staza 
	return 0;
}

static int isSpare(uint8_t frameIndex,player* player) // helper funkcija za provjeru spare a
{
	return (player->points[frameIndex] + player->points[frameIndex + 1]) == ALL_PINS_DOWN;
}

static player* getPlayerByNameAndId(char* playerName,int laneId)
{
	int i,j,k;
	k = 0;
	player* p = NULL;
	
	for(i = 0;i < numberOfLanes;i++)
	{
		for (j = 0;j < numberOfPlayers[i];j++)
		{
			if ((strcmp(players[i][j].name,playerName) == 0) && (players[i][j].lane_id == laneId))
			{
				p = &players[i][j];
				k = 1;
				break;
			}
		}
		if (k == 1)
			break;
	}
	return p;
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

int8_t* get_points_array(char* playerName,int laneId)
{
	/* points je organizovan na nacin:
	points[i*2] - vraca bodove sa prvog bacanja u i-tom frejmu
	points[i*2+1] - vraca bodove sa drugog bacanja u i-tom frejmu
	points[MAX_NUM_OF_THROWS-1] - vraca bodove sa dodatnog bacanja u zadnjem frejmu ( bitno provjeriti da li je stecen uslov za dodatno bacanje, ako nije ne treba ni ispisivati )
	bitno da znate kako bi kupili odgovarajuce bodove i ispisivali ih na ekran za odredjeni frejm
	*/
	player* p = getPlayerByNameAndId(playerName, laneId);
	
	if (p != NULL)
		return p->points;
	return NULL;
}

int16_t* get_frame_array(char* playerName,int laneId)
{
	player* p = getPlayerByNameAndId(playerName, laneId);
	
	if (p != NULL)
		return p->frames;
	return NULL;
}

int* getAllLaneIds()
{
	return laneIds;
}

char* getAllPlayersOnLane(int laneId)
{
	int i,j;
	
	for (i = 0; i < numberOfLanes; i++)
	{
		if (laneIds[i] == laneId)
			break;
	}
}

int16_t score(char* playerName,int laneId)
{
	uint8_t i; 
	uint8_t j = 0;
	player* p = getPlayerByNameAndId(playerName, laneId);
	
	if (p != NULL)
	{
	for (i = 0; i < NUM_OF_FRAMES; i++)
	{
		if (p->points[j] == ALL_PINS_DOWN)            
		{	
			if(j < LAST_FRAME_FIRST_THROW)
			{
				if (p->points[j + 2] == ALL_PINS_DOWN)          //double
				{
					p->frames[i] = p->totalScore += (ALL_PINS_DOWN + p->points[j + 2] + p->points[j + 4]);
				}							
				else				//strike
				{
					p->frames[i] = p->totalScore += (ALL_PINS_DOWN + p->points[j + 2] + p->points[j + 3]);
				}
			}
			else
			{	
				p->frames[i] = p->totalScore += (ALL_PINS_DOWN + p->points[j + 1]+ p->points[j + 2]);
						// last frame different rules
			}
		}
		else if (isSpare(j, p) && (j <= LAST_FRAME_FIRST_THROW)) // spare
		{
			p->frames[i] = p->totalScore += (ALL_PINS_DOWN + p->points[j + 2]);
		}
		else
		{
			p->frames[i] = p->totalScore += (p->points[j] + p->points[j + 1]);
		}
		j += 2;
	}
	} 
	else 
		return 0; //player->totalScore;
}
						
void knockDown(char* playerName,int laneId,uint8_t x)
{
	player* p = getPlayerByNameAndId(playerName, laneId);
	
	if (p != NULL)
	{
		if (p->numOfThrow == MAX_NUM_OF_THROWS)
		{
			//initialise();
		}	
		p->points[p->numOfThrow] = x;
		if ((x == ALL_PINS_DOWN) && (p->numOfThrow < LAST_FRAME_FIRST_THROW)) // last frame <=> different rules
		{
			p->points[++(p->numOfThrow)] = 0;  
				// ako je strike ima samo jedno bacanje u okviru => vazi za prvih devet frameova	
		}
		(p->numOfThrow)++;
	}
}

void initialise(int argc, char* argv[])
{
  
  uint8_t i, j = 2, k;
  int valid;
  valid=validate(argc, argv);
  if(valid==0)
  {
  numberOfLanes = atoi(argv[1]);
  numberOfPlayers = (int*) malloc(sizeof(int) * numberOfLanes);
  laneIds = (int*) malloc(sizeof(int) * numberOfLanes);
  char* lanePlayers[6];
  players = (player**) malloc(sizeof(player*) * numberOfLanes);
  
  for (i = 0; i < numberOfLanes; i++)
  {
     numberOfPlayers[i] = atoi(argv[j]);
	 laneIds[i] = i + 1;
     
     for(k = 0; k < numberOfPlayers[i]; k++)
     {
       lanePlayers[k] = (char*) malloc(strlen(argv[++j])+1);
       strcpy(lanePlayers[k], argv[j]);
      }
     j++;
    
     players[i] = (player*) malloc (sizeof(player) * numberOfPlayers[i]);
     createLane(numberOfPlayers[i], players[i], lanePlayers, laneIds[i]);
  }
  
  for (i = 0; i < numberOfLanes; i++)
  {
    for (j = 0; j < numberOfPlayers[i]; j++)
    {
      printf("%d\n", players[i][j].lane_id);
    }
  }
  }
}

/*static void testMemory(int* pointsCheck)
{
	uint8_t i = 0;
 	for (i = 0; i < 24; i++) 
	{
     		pointsCheck[i] = points[i];
  	}

}*/
