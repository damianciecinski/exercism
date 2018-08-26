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

#define REVERSE_CODE_MASK (1 << 4)
#define MAX_CODES (4)

const char wink[] = "wink";
const char double_blink[] = "double blink";
const char close_yours_eyes[] = "close your eyes";
const char jump[] = "jump";

const char * codes_array[] = { wink, double_blink, close_yours_eyes, jump };
const char * reversed_codes_array[] = { jump, close_yours_eyes, double_blink, wink };

const char ** commands(uint32_t code)
{
    char ** res = calloc(1, sizeof(char*));
    char ** _codes_array = (char**)codes_array;
    uint8_t it = 0;

    if(code & REVERSE_CODE_MASK)
    {
        _codes_array = (char **)reversed_codes_array;
    }

    for(uint8_t c = 0; c < MAX_CODES; c++)
    {
        if(code & 0x01)
        {
            res = (char **)realloc(res,(it + 1) * sizeof(char*));
            res[it] = _codes_array[c];
            it++;
        }

        code >>= 1;
    } 

    return (const char **)res;
}

