#ifndef BOWLING_GUI_H
#define BOWLING_GUI_H

#define ROW 34
#define COLUMN 63
#define NUM_OF_PINS 10
#define BALL_POS_ROW 33
#define BALL_POS_COL 8
#define START_LANE_ROW 0
#define START_LANE_COLON 0
#define START_PINS 5
#define min(a,b) (((a)<=(b))?(a):(b))
#define START_OF_FIRST_TRACK_ROW 5
#define END_OF_PINS_ROW 9


void initialisationLane(void);
void initialisationPins(void);
void initialisationTable(void);
void print(void);
void move(void);
void pinsDown(int);
int knockDownPins(int, int);
void populateMatrixTable(int*, int*);
unsigned int random(void);

#endif

