#ifndef BOWLING_GUI_H
#define BOWLING_GUI_H

#define ROW 20
#define COLUMN 63
#define NUM_OF_PINS 10
#define BALL_POS_ROW 19
#define BALL_POS_COL 8
#define START_LANE_ROW 23
#define START_LANE_COLON 22
#define START_PINS 5

//Ovo podrzava samo gcc kompajler
char matrix[ROW][COLUMN] = {[0 ... ROW-1][0 ... COLUMN-1] = ' '};
char bowling_pins[NUM_OF_PINS] = {[0 ... NUM_OF_PINS-1] = '!'};

char bowling_ball = 'o';

void initialisation(void);
void print(void);
void move(void);

#endif

