#include "bowling_stats.h"
#include <stdio.h>
#include <stdbool.h>




static bool isSpare(uint8_t frameIndex) // helper funkcija za provjeru spare a
{
	return points[frameIndex] + points[frameIndex+1] == ALL_PINS_DOWN;
}

int8_t* get_points_array()
{
	/* points je organizovan na nacin:
	points[i*2] - vraca bodove sa prvog bacanja u i-tom frejmu
	points[i*2+1] - vraca bodove sa drugog bacanja u i-tom frejmu
	points[MAX_NUM_OF_THROWS-1] - vraca bodove sa dodatnog bacanja u zadnjem frejmu ( bitno provjeriti da li je stecen uslov za dodatno bacanje, ako nije ne treba ni ispisivati )
	bitno da znate kako bi kupili odgovarajuce bodove i ispisivali ih na ekran za odredjeni frejm
	*/
	return points;
}
int16_t* get_frame_array()
{
	return frames;
}
 
int16_t score()
{
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
}
						
void knockDown(uint8_t x)
{
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
}

void initialise(int argc, char* argv[])
{
  uint8_t i,j = 2, k;
  
  int numberOfLanes = atoi(argv[1]);
  int numberOfPlayers;
  char players[6][10];
  
  for (i = 0;i < numberOfLanes; i++)
  {
    numberOfPlayers = atoi(argv[j]);
    
    for ( k = 0; k < numberOfPlayers; k++)
    {
  
      strcpy(players[k],argv[j++]);
    }
    createLane(numberOfPlayers, players);
    
}


void createLane(int num_of_players, char* heros[])
{
  uint8_t i,j, k;  
 
  for (k=0; k < num_of_players; k++)
  {
     
      for(i = 0; i < NUM_OF_FRAMES; i++)
      {
	  heros[k]->frames[i] = NOT_EVALUATED;
      }

      for(j = 0; j < MAX_NUM_OF_THROWS; j++)
      {
	  heros[k]->points[j] = NOT_THROWN;
      }
      
      heros[k]->totalScore = 0;
      heros[k]->numOfThrow = 0;
  }
}

static void testMemory(int* pointsCheck)
{
	uint8_t i = 0;
 	for (i = 0; i < 24; i++) 
	{
     		pointsCheck[i] = points[i];
  	}

}

bool validate(int argc, char* argv[])

{
	bool x=true;
	if(*argv[1] == '1' || *argv[1] == '2' || *argv[1] == '3')
	{			
		x=true;
	}
	else 
	{
		printf("Previse staza.\n");
		x=false;
	}
	if(*argv[2] == '1' || *argv[2] == '2' || *argv[2] == '3' || *argv[2] == '4' || *argv[2] == '5' || *argv[2] == '6')
	{	
		x=true;
	}
	else 
	{
		printf("Previse igraca.\n");
		x=false;
	}
	return x;
}
