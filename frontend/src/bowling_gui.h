#ifndef BOWLING_GUI_H
#define BOWLING_GUI_H


#define ROW_TRACK 34
#define COLUMN_TRACK 15
#define NUM_OF_PINS 10
#define BALL_POS_ROW 33
#define FIRST_BALL_POS_COL 8
#define START_LANE_ROW 0
#define START_LANE_COLON 0
#define START_PINS 5
#define DIFF 45
#define DIFF_TABLES 45
#define min(a,b) (((a)<=(b))?(a):(b))
#define START_OF_FIRST_TRACK_ROW 5
#define END_OF_PINS_ROW 9


void initialisationLane();
void initialisationTrack();
void print(int);
void move(int TrackNumber);
void pinsDown(int,int,int);
int knockDownPins(int, int,int);
void populateMatrixTable(int*, int*);
unsigned int random1(void);

#endif

