#include <stdio.h>
#include <stdlib.h>
#include "users.h"

void initialise()
{
	int numberOfLanes;
	
	do
	{
		printf("Koliko staza zelite kreirati: ");
		scanf("%d", &numberOfLanes);
	} while (numberOfLanes < 1 || numberOfLanes > 3);
	
	allLanes = (lane*) calloc(numberOfLanes, sizeof(lane));
}

/*int main()		//koristiti samo dok traje pokretanje bez ulinkavanja sa ostatkom
{
	return 0;
} */