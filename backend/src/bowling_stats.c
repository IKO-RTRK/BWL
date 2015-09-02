#include "bowling_stats.h"


static int score[21];
static int currentPosition;

int* skor()
{
  return score;
}


int srusi(int x)
{
  score[currentPosition] = x;
  currentPosition++;
}

