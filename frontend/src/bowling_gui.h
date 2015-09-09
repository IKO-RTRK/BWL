#ifndef BOWLING_GUI_H
#define BOWLING_GUI_H


#define NUM_OF_PINS 10
#define BALL_POS_ROW 33
#define FIRST_BALL_POS_COL 8
#define START_LANE_ROW 0
#define START_LANE_COLON 0
#define START_PINS 5
#define DIFF_TRACKS 56
#define DIFF_TABLES 5
#define min(a,b) (((a)<=(b))?(a):(b))
#define START_OF_FIRST_TRACK_ROW 5
#define END_OF_PINS_ROW 9

#include "traka.h"
#include "../../backend/src/users.h"

traka array[3];

void initialisationLane(traka* t);
void initialisationTrack(traka* t);
void initialisationTable(lane *l,traka * t);
void print_track(lane*,traka*);
void print_table(lane*,traka*);
void print();
void move(int TrackNumber);
void pinsDown(int,int,int);
int knockDownPins(int, int,int);
void populateMatrixTable(int*, int*);
unsigned int random1(void);
void ShowTrack (lane *,traka *);

#endif

