#include "bowling_stats.h"

int frejmovi[10];
int poeni[21];

int skor()
{
	return 0;
}

void srusi(int x)
{
	return;
}
void inicijalizacija()
{
  int i,j;
  for(i = 0; i < BROJ_FREJMOVA; i++)
  {
      frejmovi[i] = 0;
  }
  for(j = 0; j < MAX_BROJ_BACANJA; j++)
  {
      poeni[j] = 0;
  }

}
