#include "bowling_stats.h"
#include <stdio.h>

int frejmovi[10];
int poeni[21];
static int skorUkupan;

int skor()
{
	return skorUkupan;
}

void srusi(int x)
{
	int i;
	for (i = 0; i < MAX_BROJ_BACANJA; i++)
	{
		skorUkupan += x;	
	}
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
