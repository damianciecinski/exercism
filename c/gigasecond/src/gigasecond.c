
/*
 * gigasecond.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "gigasecond.h" 

#include <stdint.h>
#include <limits.h>


time_t gigasecond_after(time_t time)
{
    time_t giga = 1e9;
    time_t res = 0;
    
    if(time > 0 && giga > LONG_MAX - time)
    {
        res = -1;
    }
    else
    {
        res = time + giga;
    }
    
    return res;	
}
