#include "bowling_stats.h"


static int score[21];
static int currentPosition;

int* throws()
{
  return score;
}


int srusi(int x)
{
  if (x < 0 || x > 10 ) 
  {
    x = 0;
  }
  score[currentPosition] = x;
  currentPosition++;
}

