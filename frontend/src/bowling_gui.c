#include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
#include "bowling_gui.h"

void initialisation(void) 
{
    int curr_row;
    int curr_column;
    int counter = NUM_OF_PIN - 1;
    
    
    for (curr_row = 0; curr_row < ROW; curr_row++)
    {
	matrix[curr_row][0] = '|';
	matrix[curr_row][2] = '|';
	matrix[curr_row][14] = '|';
	matrix[curr_row][16] = '|';
    }

    
    int tmp = 0, tmp1;
    int n = 5;

    //unosenje cunjeva u matricu
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
    system("clear");
    print();
    usleep(700000);
    return;
}

void followBumper(int curr_pos_row,int in_field_column)
{
  int column;
  if (in_field_column == 2)
    column = 1;
  else
    column = 15;
  
  int prev_pos_row = curr_pos_row--;
  matrix[prev_pos_row][in_field_column] = '.';
  
  while (curr_pos_row > 0)
  {
    prev_pos_row = curr_pos_row;
    curr_pos_row -= 1;
    
    matrix[prev_pos_row][column] = '.';
    matrix[curr_pos_row][column] = bowling_ball;
    system("clear");
    print();
    usleep(700000);
  }
}

void move(void)
{ 
    int offset;
    int curr_pos_row = BALL_POS_ROW;
    int curr_pos_col = BALL_POS_COL;
    int prev_pos_row;
    int prev_pos_col;
    double a, b;		// koriste se samo za funkciju foo1
    while (curr_pos_row >= 5)
    {
      if (curr_pos_col < 2 || curr_pos_col > 14)
	offset = 0;
      else
      {
	foo1(a,b); //napisao sam je samo da bih mogao dobiti bolje vrijednosti za random
		    //ako se ko sjeti neceg pametnijeg neka optimizuje
		  //bez neceg ovakvog random vraca uvijek istu vrijednost
		// ni u kojem slucaju ovo ovako ostaviti
	a += 2.435;
	b += 4.353;
	offset = (random() % 3) - 1;
      }
      
      prev_pos_row = curr_pos_row;
      prev_pos_col = curr_pos_col;
      
      curr_pos_row -= 1;
      curr_pos_col = curr_pos_col + offset;
	
      matrix[prev_pos_row][prev_pos_col] = '.';
      matrix[curr_pos_row][curr_pos_col] = bowling_ball;
      system("clear");
      print();
      usleep(700000);
      
      //da li je kugla upala u kanal
      if (curr_pos_col == 2 || curr_pos_col == 14)
      {
	followBumper(curr_pos_row,curr_pos_col);	//sprovedi kuglu kroz kanal
	curr_pos_row = 4;
      }
    }
}

//Ispis matrice
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
  move();
  return 0;
}