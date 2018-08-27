/*
 * secret_handshake.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "secret_handshake.h"

#define REVERSE_CODE_MASK (1UL << 4)
#define MAX_CODES (4)

const char * codes_array[] = { "wink", "double blink", "close your eyes", "jump" };

/**
 * @brief Convert given a decimal number to the appropriate 
 *        sequence of events for a secret handshake.
 *
 * @param code secret code
 *
 * @return pointer to the list of the secret handshakes  
 */
const char ** commands(uint8_t code)
{
    uint8_t indexes[MAX_CODES] = {0};
    uint8_t _code = code;
    uint8_t it = 0;

    for(uint8_t c = 0; c < MAX_CODES; c++)
    {
        if(_code & 0x01)
        {
            indexes[it++] = c;
        }

        _code >>= 1;
    } 

    char const ** res = calloc(it, sizeof(char *));

    for(uint8_t i = 0; i < it; i++)
    {
        if(code & REVERSE_CODE_MASK)
        {
            res[it - 1 - i] = codes_array[indexes[i]];
        }
        else
        {
            res[i] = codes_array[indexes[i]];
        }
    }

    return res;
}

