#ifndef TRAKA_H
#define TRAKA_H

#define ROW_TRACK 34
#define COLUMN_TRACK 15
#define ROW_TABLE 4
#define COLUMN_TABLE 41

typedef struct track
{
char matrix_track[ROW_TRACK][COLUMN_TRACK];
char matrix_table[6][ROW_TABLE][COLUMN_TABLE];
int ballX; //koordinate kugle
int ballY;

}traka;



#endif
