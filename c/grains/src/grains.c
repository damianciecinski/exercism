/*
 * grains.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "grains.h"

uint64_t square(uint8_t s)
{
    uint64_t res = 0;

    if(s > 0 && s < 65)
    {
        res = 1;
        for(uint8_t i = 2; i <= s; i++)
        {
            res = res * 2;
        }
    }
    
    return res;
}

