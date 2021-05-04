
#include <stdio.h>  /* printf fprintf */
#include <time.h>   /* clock_nanosleep */
#include <sys/time.h>   /* clock_nanosleep */
#include <sys/syscall.h>   /* clock_nanosleep */
#include "fabio.h"


void wait_ms(unsigned long a) 
{
    struct timespec dly;
    struct timespec rem;

    printf("WAIT1 NOTE WAIT_MS : %ld\n", a);


    return;
}
