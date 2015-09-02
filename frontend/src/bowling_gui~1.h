#ifndef BOWLING_GUI_H
#define BOWLING_GUI_H

#define ROW 20
#define COLUMN 18
#define ROW_TABLE 4
#define COLUMN_TABLE 41
#define NUM_OF_PINS 10
#define BALL_POS_ROW 19
#define BALL_POS_COL 6
#define START_LANE_ROW 1
#define START_LANE_COLON 0
#define START_PINS 3


void initialisationLane(void);
void initialisationPins(void);
void initialisationTable(void);
void print(void);
void move(void);
void pinsDown(int);
int knockDown(int);
void populateMatrixTable(int*, int*);

// Neki random sa kojim sam radio... Slobodno se moze kasnije izbaciti
unsigned int random7(void);

#endif

