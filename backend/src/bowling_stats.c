#include "bowling_stats.h"
#include <stdio.h>

int frames[NUM_OF_FRAMES];
int points[MAX_NUM_OF_THROWS]; 
static int totalScore;
static int numOfThrow;

//Pokusaj rjesenja poslednjeg frame-a i onemogucavanja pristupa lokacijama points[x] : x>20
//Vjerovatno postoji elegantnije rjesenje
int score()
{
	int i; 
	int j = 0;
	for (i = 0; i < NUM_OF_FRAMES; i++)
	{
		if (points[j] == 10)            
		{	
			if(j<LAST_FRAME_FIRST_THROW)
			{
				if (points[j+2] == 10)          //double
				totalScore += (10 + points[j+2] + points[j+4]);
							
				else				//strike
				totalScore += (10 + points[j+2] + points[j+3]);
			}
			else
				totalScore += (10 + points[j+1]);// last frame different rules

		}
		else if ((points[j] + points[j+1] == 10) && (j<LAST_FRAME_FIRST_THROW))  // spare
			totalScore += (10 + points[j+2]);
		else
		totalScore += (points[j] + points[j+1]);

		j += 2;

		if(j==(MAX_NUM_OF_THROWS-1))
			totalScore += points[j];   // zadnji okvir ima 3 bacanja
	}

}

void knockDown(int x)
{
	if (numOfThrow == MAX_NUM_OF_THROWS)
	initialise();
	
	points[numOfThrow] = x;
	if ((x == 10) && (numOfThrow<LAST_FRAME_FIRST_THROW)) // last frame <=> different rules
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
