#include "bowling_stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


static int isSpare(player* p, int8_t index)
{
	return ((p -> points[index] + p -> points[index + 1]) == ALL_PINS_DOWN);
}


static void score(player* p)
{
	uint8_t i; 
	uint8_t j = 0;

	p->totalScore = 0;

	int8_t k = p -> numOfThrow / 2;
	
	for (i = 0; i < k; i++) 
	{
		if (p -> points[j] == ALL_PINS_DOWN)            
		{	
			if(j < LAST_FRAME_FIRST_THROW)
			{
				if (p -> points[j + 2] == ALL_PINS_DOWN)           // Double
				{
					p -> frames[i] = p -> totalScore += (ALL_PINS_DOWN + p -> points[j + 2] + p -> points[j + 4]);
				}							
				else				                   // Strike
				{
					p -> frames[i] = p -> totalScore += (ALL_PINS_DOWN + p -> points[j + 2] + p -> points[j + 3]);
				}
			}
			else
			{	
				p -> frames[i] = p -> totalScore += (ALL_PINS_DOWN + p -> points[j + 1] + p -> points[j + 2]);
			}
		}
		else if (isSpare(p, j) && (j <= LAST_FRAME_FIRST_THROW))           // Spare
		{
			p -> frames[i] = p -> totalScore += (ALL_PINS_DOWN + p -> points[j + 2]);
		}
		else
		{
			p -> frames[i] = p -> totalScore += (p -> points[j] + p -> points[j + 1]);
		}
		j += 2;
	}
}
						
void knockDown(player* p, uint8_t x)
{	
	if (p->numOfThrow == MAX_NUM_OF_THROWS)
	{
		p->numOfThrow = 0;
	}
	
	p -> points[p -> numOfThrow] = x;

	if ((x == ALL_PINS_DOWN) && (p -> numOfThrow < LAST_FRAME_FIRST_THROW)) 
	{
		p->points[++(p->numOfThrow)] = 0;  	
	}
	
	(p->numOfThrow)++;
	
	if ((p -> numOfThrow % 2 == 0 && p -> numOfThrow != 0) || p -> numOfThrow  == MAX_NUM_OF_THROWS)
	score(p);
}
