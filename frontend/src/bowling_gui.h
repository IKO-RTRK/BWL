#ifndef BOWLING_GUI_H
#define BOWLING_GUI_H

#define ROW 20
#define COLUMN 63
#define NUM_OF_BALL 10
#define BALL_POS_ROW 19
#define BALL_POS_COL 8

char matrix[ROW][COLUMN] = {[0 ... ROW-1][0 ... COLUMN-1] = ' '};
char bowling_pins[NUM_OF_BALL] = {[0 ... NUM_OF_BALL-1] = '!'};
char bowling_ball = 'o';
void print(void);
void initialisation(void);

#endif

