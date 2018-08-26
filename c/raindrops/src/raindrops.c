/*
 * raindrops.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <string.h>
#include <stdio.h>

#include "raindrops.h"

#define MAX_LENGTH (16)

const char pling[] = "Pling";
const char plang[] = "Plang";
const char plong[] = "Plong";

/**
 * @brief Convert a drops number to a string accordingly to the 
 *        following conditions:
 *        - if the number has 3 as a factor, output 'Pling'
 *        - if the number has 5 as a factor, output 'Plang'
 *        - if the number has 7 as a factor, output 'Plong'
 *        - if the number does not have 3, 5, or 7 as a factor, 
 *          just pass the number's digits straight through
 *
 * @param buffer
 * @param drops
 */
void convert(char * buffer, int drops)
{
    uint8_t write_ptr = 0;
    
    if(drops % 3 == 0)
    {
        strncpy(buffer + write_ptr, pling, MAX_LENGTH - write_ptr);
        write_ptr += strlen(pling);
    }
    
    if(drops % 5 == 0)
    {
        strncpy(buffer + write_ptr, plang, MAX_LENGTH - write_ptr);
        write_ptr += strlen(plang);
    }

    if(drops % 7 == 0)
    {
        strncpy(buffer + write_ptr, plong, MAX_LENGTH - write_ptr);
        write_ptr += strlen(plong);
    }

    if(0 == write_ptr)
    {
        snprintf(buffer, MAX_LENGTH, "%d", drops); 
    }
}
