#include "bowling_stats.h"
#include <stdio.h>

int frejmovi[10];
int poeni[21];
static int skorUkupan;
static int brBacanja;

int skor()
{
	return skorUkupan;
}

void srusi(int x)
{
	skorUkupan += x;	
	brBacanja++;
	if (brBacanja == MAX_BROJ_BACANJA)
	inicijalizacija();
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

  skorUkupan = 0;

}
