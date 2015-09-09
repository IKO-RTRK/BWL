#ifndef TRAKA_H
#define TRAKA_H


typedef struct track
{
char matrix_track[ROW_TRACK][COLUMN_TRACK] = {[0 ... ROW_TRACK-1][0 ... COLUMN_TRACK-1] = ' '};
char matrix_table[6][ROW_TABLE][COLUMN_TABLE] = {[0 ... ROW_TABLE-1][0 ... COLUMN_TABLE-1] = ' '};
int ballX; //koordinate kugle
int ballY;

}traka;



#endif
