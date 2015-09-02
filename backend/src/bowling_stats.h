#ifndef BOWLING_STATS_H
#define BOWLING_STATS_H
#define NUM_OF_FRAMES 10
#define MAX_NUM_OF_THROWS 21
#define LAST_FRAME_FIRST_THROW 18
#define ALL_PINS_DOWN 10
#define NOT_EVALUATED -1
#define NOT_THROWN -1
#include <stdint.h>

void initialise();
int16_t score();
void knockDown(uint8_t x);
void testMemory(int* pointsCheck);
int8_t* get_points_array(); // zvati score() prije ovoga, vraca pokazivac na pocetak niza statistike, objasnjenje je u fajlu sa implementacijom
int16_t* get_frames_array(); // zvati score() prije ovoga, vraca pokazivac na pocetak niza bodova u svakom frejmu
#endif
