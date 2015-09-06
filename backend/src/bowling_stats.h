#ifndef BOWLING_STATS_H
#define BOWLING_STATS_H
#define NUM_OF_FRAMES 10
#define MAX_NUM_OF_THROWS (NUM_OF_FRAMES*2 + 1)
#define LAST_FRAME_FIRST_THROW 18
#define ALL_PINS_DOWN 10
#define NOT_EVALUATED -1
#define NOT_THROWN -1
#include <stdint.h>

typedef struct Player 
{
    char* name;
    int16_t frames[NUM_OF_FRAMES];
    int8_t points[MAX_NUM_OF_THROWS]; 
    uint16_t totalScore; //max score je 300 pa koristimo uint16_t
    uint8_t numOfThrow;
    int lane_id;
} player;

void initialise(int argc, char* argv[]);
int16_t score(char* playerName,int laneId);
void knockDown(char* playerName,int laneId,uint8_t x);
//int validate(int ,char* []);
int8_t* get_points_array(char* playerName,int laneId); // zvati score() prije ovoga, vraca pokazivac na pocetak niza statistike, objasnjenje je u fajlu sa implementacijom
int16_t* get_frames_array(char* playerName, int laneId); // zvati score() prije ovoga, vraca pokazivac na pocetak niza bodova u svakom frejmu
char* getAllPlayersOnLane(int laneId);
int* getAllLaneIds();
#endif
