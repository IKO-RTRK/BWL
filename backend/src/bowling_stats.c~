#include "bowling_stats.h"
#include <stdio.h>

int frames[NUM_OF_FRAMES];
int points[MAX_NUM_OF_THROWS]; 
static int totalScore;
static int numOfThrow;

int score()
{
	int i; 
	int j = 0;
	for (i = 0; i < NUM_OF_FRAMES; i++)
	{
		if (points[j] == ALL_PINS_DOWN)            
		{	
			if(j<LAST_FRAME_FIRST_THROW)
			{
				if (points[j+2] == ALL_PINS_DOWN)          //double
				totalScore += (ALL_PINS_DOWN + points[j+2] + points[j+4]);
							
				else				//strike
				totalScore += (ALL_PINS_DOWN + points[j+2] + points[j+3]);
			}
			else
				totalScore += (ALL_PINS_DOWN + points[j+1]);// last frame different rules

		}
		else if ((points[j] + points[j+1] == ALL_PINS_DOWN) && (j<LAST_FRAME_FIRST_THROW))  // spare
			totalScore += (ALL_PINS_DOWN + points[j+2]);
		else
		totalScore += (points[j] + points[j+1]);

		j += 2;

		if(j==(MAX_NUM_OF_THROWS-1))
			totalScore += points[j];   // zadnji okvir ima 3 bacanja
	}

	return totalScore;
}

void knockDown(int x)
{
	if (numOfThrow == MAX_NUM_OF_THROWS)
	initialise();
	
	points[numOfThrow] = x;
	if ((x == ALL_PINS_DOWN) && (numOfThrow<LAST_FRAME_FIRST_THROW)) // last frame <=> different rules
	{
		points[++numOfThrow] = 0;  // ako je strike ima samo jedno bacanje u okviru => vazi za prvih devet frameova	
	}
	numOfThrow++;
}

void initialise()
{
  int i,j;

  for(i = 0; i < NUM_OF_FRAMES; i++)
  {
      frames[i] = 0;
  }

  for(j = 0; j < MAX_NUM_OF_THROWS; j++)
  {
      points[j] = 0;
  }

  totalScore = 0;
  numOfThrow = 0;

}

void testMemory(int* pointsCheck)
{
	int i=0;
 	for (i = 0; i < 24; i++) {
     	pointsCheck[i] = points[i];
  	}

}
