#include "bowling_stats.h"
#include <stdio.h>



int16_t frames[NUM_OF_FRAMES];
int8_t points[MAX_NUM_OF_THROWS]; 
static uint16_t totalScore; //max score je 300 pa koristimo uint16_t
static uint8_t numOfThrow;


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
				if (points[j+2] == ALL_PINS_DOWN)          //double
				frames[i] = totalScore += (ALL_PINS_DOWN + points[j+2] + points[j+4]);
							
				else				//strike
				frames[i] = totalScore += (ALL_PINS_DOWN + points[j+2] + points[j+3]);
			}
			else
				frames[i] = totalScore += (ALL_PINS_DOWN + points[j+1]+ points[j+2]);// last frame different rules

		}
		else if ((points[j] + points[j+1] == ALL_PINS_DOWN) && (j<=LAST_FRAME_FIRST_THROW))  // spare
			frames[i] = totalScore += (ALL_PINS_DOWN + points[j+2]);
		else
		frames[i] = totalScore += (points[j] + points[j+1]);

		j += 2;

	}
	return totalScore;
}

void knockDown(uint8_t x)
{
	if (numOfThrow == MAX_NUM_OF_THROWS)
	initialise();
	
	points[numOfThrow] = x;
	if ((x == ALL_PINS_DOWN) && (numOfThrow < LAST_FRAME_FIRST_THROW)) // last frame <=> different rules
	{
		points[++numOfThrow] = 0;  // ako je strike ima samo jedno bacanje u okviru => vazi za prvih devet frameova	
	}
	numOfThrow++;
}

void initialise()
{
  uint8_t i,j;

  for(i = 0; i < NUM_OF_FRAMES; i++)
  {
      frames[i] = NOT_EVALUATED;
  }

  for(j = 0; j < MAX_NUM_OF_THROWS; j++)
  {
      points[j] = NOT_THROWN;
  }

  totalScore = 0;
  numOfThrow = 0;

}

void testMemory(int* pointsCheck)
{
	uint8_t i=0;
 	for (i = 0; i < 24; i++) {
     	pointsCheck[i] = points[i];
  	}

}
