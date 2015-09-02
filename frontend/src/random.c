#include <math.h>

int random(void)
{
     static unsigned int zi,zii;
     
     zi=(1103515245* zii + 12345)% (int)pow(2,32) ;
     zii=zi;
             return zi ;
}

