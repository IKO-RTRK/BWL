#include "bowling_stats.h"


static int score[21];
static int currentPosition;

int* throws(void)
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

void newGame(void)
{
  int i;
  for (i = 0; i < 21; i++)
  {
    score[i] = 0;
  }
  currentPosition = 0;
}