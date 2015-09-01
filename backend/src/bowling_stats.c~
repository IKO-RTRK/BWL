#include "bowling_stats.h"
#include <stdio.h>

int frames[10];
int points[21];
static int totalScore;
static int numOfThrow;

int score()
{
	int i; 
	int j = 0;
	for (i = 0; i < NUM_OF_FRAMES; i++)
	{
		if (points[j] == 10)                    // strike
		{
			if (points[j+2] == 10)
			totalScore += (10 + points[j+2] + points[j+4]);
			else
			totalScore += (10 + points[j+2] + points[j+3]);
		}
		else if (points[j] + points[j+1] == 10)  // spare
		totalScore += (10 + points[j+2]);
		else
		totalScore += (points[j] + points[j+1]);

		j += 2;
	}

	if(totalScore != 300)

	totalScore += points[MAX_NUM_OF_THROWS-1];   // zadnji okvir ima 3 bacanja
	return totalScore;
}

void knockDown(int x)
{
	if (numOfThrow == MAX_NUM_OF_THROWS)
	initialise();
	
	points[numOfThrow++] = x;
	if (x == 10)
	{
		points[numOfThrow++] = 0;  // ako je strike ima samo jedno bacanje u okviru	
	}
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
