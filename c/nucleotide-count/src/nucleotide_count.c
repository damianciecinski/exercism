/*
 * nucleotide_count.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "nucleotide_count.h"

char * count(const char * dna_strand)
{
    char *ret = NULL;
    uint32_t a = 0, c = 0, g = 0, t = 0;
    bool invalid_input = false;

    if(NULL != dna_strand)
    {
        for(uint32_t s = 0; dna_strand[s] != 0; s++)
        {
            if('A' == dna_strand[s])
            {
                a++;
            }
            else if('C' == dna_strand[s])
            {
                c++;
            }
            else if('G' == dna_strand[s])
            {
                g++;
            }
            else if('T' == dna_strand[s])
            {
                t++;
            }
            else
            {
                invalid_input = true;
                ret = calloc(1, 1);
                break;
            }
        }
    
        if(false == invalid_input)
        {
            asprintf(&ret, "A:%d C:%d G:%d T:%d", a, c, g, t);
        }
    }

    return ret;
}

