/*
 * beer_song.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "beer_song.h"

static uint32_t pointer = 0;

static uint32_t get_bottle_txt(char * response, uint8_t bottle, bool capital_letter)
{
    uint32_t res = 0;

    if(0 == bottle)
    {
        res = sprintf(response, "%co more bottles", capital_letter ? 'N' : 'n');
    }
    else
    {
        res = sprintf(response, "%d %s", bottle, bottle > 1 ? "bottles" : "bottle");
    }

    return res;
}

void verse(char * response, uint8_t verse)
{
    uint32_t ptr = 0;
    
    /* prepare first sentence */
    ptr += get_bottle_txt(response + ptr, verse, true);
    ptr += sprintf(response + ptr, " of beer on the wall, ");
    ptr += get_bottle_txt(response + ptr, verse, false);        
    ptr += sprintf(response + ptr, " of beer.\n");

    /* prepare first part of second sentece */
    ptr += sprintf(response + ptr, "%s", verse == 0 ? "Go to the store and buy some more, " :
        verse == 1 ? "Take it down and pass it around, " : "Take one down and pass it around, ");

    /* prepare second part of second sentence */
    ptr += get_bottle_txt(response + ptr, verse == 0 ? 99 : verse - 1, false);
    ptr += sprintf(response + ptr, " of beer on the wall.\n");

    pointer += ptr;
}

void sing(char * response, uint8_t verse_start, uint8_t verse_stop)
{
    pointer = 0;

    for(int8_t v = verse_start; v >= verse_stop; v--)
    {
        verse(response + pointer, v);
        if(v != verse_stop) 
        {
            response[pointer++] = '\n';
        }
    }
}
