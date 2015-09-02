#include <math.h>

int random(void)
{
     static unsigned int zi,zii;
     
     zi=(1103515245* zii + 12345) % 2147483648 ;
     zii=zi;
             return zi ;
}

