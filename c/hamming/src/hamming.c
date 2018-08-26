/*
 * hamming.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <string.h>

#include "hamming.h"


/**
 * @brief Calculate the Hamming difference between two DNA strands.
 *
 * @param dna_strand1 input text for DNA strand 1
 * @param dna_strand2 input text for DNA strand 2
 *
 * @return how many differences there is
 */
int32_t compute(const char * dna_strand1, const char * dna_strand2)
{
    int32_t res = -1;

    if(dna_strand1 != NULL && dna_strand2 != NULL)
    {
        size_t len_dna_strand1 = strlen(dna_strand1);
        size_t len_dna_strand2 = strlen(dna_strand2);

        if(len_dna_strand1 == len_dna_strand2)
        {
            res = 0;
            for(size_t n = 0U; n < len_dna_strand1; n++)
            {
                if(dna_strand1[n] != dna_strand2[n])
                {
                    res++;
                }
            }
        }
    }

    return res;
}

