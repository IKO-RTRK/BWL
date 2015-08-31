#include <stdio.h>
#include "bowling_gui.h"

void initialisation(void) 
{
    int curr_row;
    int curr_column;
    int counter = NUM_OF_BALL - 1;

    for (curr_row = 0; curr_row < ROW; curr_row++)
    {
	matrix[curr_row][0] = '|';
	matrix[curr_row][2] = '|';
	matrix[curr_row][14] = '|';
	matrix[curr_row][16] = '|';
    }

    
    int tmp = 0, tmp1;
    int n = 5;

    //unosenje cunjeva u mapu
    for (curr_row = 4; curr_row > 0; curr_row--)
    {
	tmp1 = n;
	for (curr_column = curr_row; curr_column > 0; curr_column--)
	{
	    matrix[tmp][tmp1] = bowling_pins[counter--];
	    tmp1+=2;
	}
	tmp++;
	n++;
    }

    matrix[BALL_POS_ROW][BALL_POS_COL] = bowling_ball;

    tmp = 22;
    tmp1 = 23;

    for (curr_row = 0; curr_row < 10; curr_row++)
    {
	for (curr_column = 0; curr_column < 3; curr_column++) 
	{
	    matrix[0][tmp1 + curr_column] = '-';
	    matrix[3][tmp1 + curr_column] = '-';
	}

	tmp1+=4;
    }

    for (curr_row = 0; curr_row < 11; curr_row++)
    {
	for (curr_column = 0; curr_column < 2; curr_column++) 
	{
	    matrix[1][tmp] = '|';
	    matrix[2][tmp] = '|';
	}
	tmp+=4;
    }

    matrix[1][23] = '_';
    matrix[1][25] = '1';
    matrix[2][25] = '1';
    return;
}

void print(void)
{
    int curr_row;
    int curr_column;
    
    for (curr_row = 0; curr_row < ROW; curr_row++) 
    {
	for (curr_column = 0; curr_column < COLUMN; curr_column++)
	{
	    printf("%c", matrix[curr_row][curr_column]);
	}
	printf("\n");
    }
    return;
}

int main(void)
{
  initialisation();
  print();
  return 0;
}