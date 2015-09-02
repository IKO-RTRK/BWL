#ifndef BOWLING_STATS_H
#define BOWLING_STATS_H
#define NUM_OF_FRAMES 10
#define MAX_NUM_OF_THROWS 21
#define LAST_FRAME_FIRST_THROW 18
#define ALL_PINS_DOWN 10
#include <stdint.h>

void initialise();
int score();
void knockDown(uint8_t x);
void testMemory(int* pointsCheck);

#endif
