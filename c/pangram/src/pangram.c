/*
 * pangram.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "pangram.h"

#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

#define NUMBER_OF_CHAR ('z'-'a' + 1)

/**
 * @brief Determine if a sentence is a pangram.
 *
 * @param sentence input text
 *
 * @return true: is a pangram, false: it is not
 */
bool is_pangram(const char *sentence)
{
    bool res = false;
    
    if(sentence != NULL)
    {
        res = true;
        bool is_char[NUMBER_OF_CHAR] = {0};
        uint32_t len = strlen(sentence);

        for(uint16_t c = 0; c < len; c++)
        {
            if(isalpha(sentence[c]))
            {
                is_char[tolower(sentence[c]) - 'a'] = true;
            }
        }
        
        for(uint8_t c = 0; c < NUMBER_OF_CHAR; c++)
        {
            res = res && is_char[c];    
        }
    }

    return res;
}


