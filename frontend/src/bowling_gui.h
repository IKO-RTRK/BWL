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
#define min(a,b) (((a)<=(b))?(a):(b))

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void initialisationLane(void);
void initialisationPins(void);
void initialisationTable(void);
void print(void);
void move(void);
void pinsDown(int,int*,int);
int knockDownPins(int, int);
void populateMatrixTable(int*, int*);
unsigned int random(void);

#endif

