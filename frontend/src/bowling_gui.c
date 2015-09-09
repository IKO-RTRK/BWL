#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include  <stdint.h>
#include "bowling_gui.h"

traka array[3];

char bowling_pins[NUM_OF_PINS] = {[0 ... NUM_OF_PINS-1] = '!'};
char bowling_ball = 'o';

void SetCursorPos(int XPos, int YPos)
{
 	printf("\033[%d;%dH", YPos+1, XPos+1);
}

void initialisationLane(traka* t)
{
    uint8_t curr_row;
    uint8_t curr_column;
    uint8_t j;
    //unos staze
	t->ballX=FIRST_BALL_POS_COL;
	t->ballY=BALL_POS_ROW;
    for (curr_row = END_OF_PINS_ROW ; curr_row < ROW_TRACK; curr_row++)
      {
	for(j=5;j<12;j++)
	  {
		t->matrix_track[curr_row][j] = ' ';
	  }
	t->matrix_track[curr_row][3] = ' ';
	t->matrix_track[curr_row][13] = ' ';
	t->matrix_track[curr_row][2] = '|';
	t->matrix_track[curr_row][4] = '|';
	t->matrix_track[curr_row][12] = '|';
	t->matrix_track[curr_row][14] = '|';
      }
    
    t->matrix_track[BALL_POS_ROW][FIRST_BALL_POS_COL] = bowling_ball;  //pocetna pozicija na kojoj ce se nalaziti kugla
    return;
}


void initialisationPins(traka* t)
{
    uint8_t curr_row;
    uint8_t curr_column;
    uint8_t counter = NUM_OF_PINS - 1;
    uint8_t tmp = START_OF_FIRST_TRACK_ROW, tmp1;
    uint8_t n = START_PINS;

    //unosenje cunjeva u matricu
    for (curr_row =END_OF_PINS_ROW; curr_row > START_OF_FIRST_TRACK_ROW; curr_row--)
    {
	t->matrix_track[tmp][2] = '|';
	t->matrix_track[tmp][4] = '|';
	t->matrix_track[tmp][12] = '|';
	t->matrix_track[tmp][14] = '|';

	tmp1 = n;
	for (curr_column = curr_row; curr_column >START_OF_FIRST_TRACK_ROW; curr_column--)
	{
	    t->matrix_track[tmp][tmp1] = bowling_pins[counter--];
	    tmp1+=2;
	}
	tmp++;
	n++;
	
    }
    return;
}
    
void initialisationTrack(traka* t)
{
	initialisationPins(t);
	initialisationLane(t);
}

void initialisationTable(lane *l,traka * t)
{   
	int temp=0;
	while(temp<l->numberOfPlayers)
	{		
    		uint8_t curr_row;
		uint8_t curr_column;
		uint8_t tmp1 = START_LANE_ROW;				//prvi red od koga pocinju da se upisuju -
		for (curr_row = 0; curr_row < 10; curr_row++)
		{
			for (curr_column = 1; curr_column < 4; curr_column++) 
			{
				t->matrix_table[temp][0][tmp1 + curr_column] = '-';
				t->matrix_table[temp][3][tmp1 + curr_column] = '-';
			}

			tmp1+=4;
		 }
		
		 uint8_t tmp = START_LANE_COLON;				//prva kolona od koje pocinju da se upisuju |

		 for (curr_row = 0; curr_row < 11; curr_row++)
		 {
			for (curr_column = 0; curr_column < 2; curr_column++) 
			{
				t->matrix_table[temp][1][tmp] = '|';
				t->matrix_table[temp][2][tmp] = '|';
			}
			tmp+=4;
		 }
				    
         	temp++;
	}				    
}


void ShowTrack(lane* l, traka* t)
{
	initialisationTrack(t);
	initialisationTable(l,t);
	print_table(l,t);
	print_track(l,t);	
	initialisationTrack(t+1);
	initialisationTable(l+1,t+1);
	print_table(l+1,t+1);
	print_track(l+1,t+1);
	initialisationTrack(t+2);
	initialisationTable(l+2,t+2);
	print_table(l+2,t+2);
	print_track(l+2,t+2);
}


//Ispis matrice
void print_track(lane *l,traka* t)
{
    uint8_t curr_lane;
    uint8_t curr_row;
    uint8_t curr_column;
    for (curr_lane = 0; curr_lane < numberOfLanes; curr_lane++)
	{
	    for (curr_row = 0; curr_row < ROW_TRACK; curr_row++) 
	    {
		for (curr_column = 0; curr_column < COLUMN_TRACK; curr_column++)
		{
	 	    SetCursorPos((curr_lane * DIFF_TRACKS)+curr_column, curr_row + 1);
		    printf("%c", t->matrix_track[curr_row][curr_column]);
		}
	    }
	}
    return;
}


void print_table(lane* l,traka* t)
{
    uint8_t curr_table;
    uint8_t curr_row;
    uint8_t curr_column;
    for (curr_table = 0; curr_table < l->numberOfPlayers; curr_table++)
	{
	    for (curr_row = 0; curr_row < ROW_TABLE; curr_row++) 
	    {
		for (curr_column = 0; curr_column < COLUMN_TABLE; curr_column++)
		{
	 	    SetCursorPos((l->laneId * DIFF_TRACKS) + curr_column + 16,(curr_table * DIFF_TABLES) + curr_row + 7);
		    printf("%c", t->matrix_table[l->currentPlayer][curr_row][curr_column]);
		}
	    }
	}
    return;
}

/*void print()
{
	uint8_t NumOfPlayers;
	print_track(3);
	for(NumOfPlayers = 0; NumOfPlayers < 3; NumOfPlayers++)
	{
		print_table(5,NumOfPlayers);
	}
	SetCursorPos(100,0);
}*/



unsigned int random1(void)
{
     static unsigned int zi;
     
     zi=(1103515245* zi + 12345) % 2147483648 ;
             return zi ;
}


int main(void)
{

	initialise(3);
	createLane(0, 3);
	createLane(1, 1);
	createLane(2, 2);
	allLanes->numberOfPlayers=3;
	(allLanes+1)->numberOfPlayers=1;
	(allLanes+2)->numberOfPlayers=2;
	ShowTrack (allLanes, array);
} 
