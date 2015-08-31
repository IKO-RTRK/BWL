#include <stdio.h>
#include <time.h>
int random()
{
    time_t sec;
    sec = time (NULL);
    return (int)sec;
}
