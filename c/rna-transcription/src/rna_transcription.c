/*
 * rna_transcription.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "rna_transcription.h"


/**
 * @brief Convert DNA to RNA strands
 *
 * @param dna sequence of dna
 *
 * @return sequence of rna
 */
char * to_rna(const char * dna)
{
    char * res = NULL;
    if(NULL != dna)
    {
        size_t len = strlen(dna);
        if(len > 0)
        {
            res = calloc(len + 1, sizeof(char));
            bool invalid_dna_code = false;
            for(size_t i = 0; i < len; i++)
            {
                switch(dna[i])
                {
                    case 'G':
                        {
                            res[i] = 'C';
                            break;
                        }
                    case 'C':
                        {
                            res[i] = 'G';
                            break;
                        }
                    case 'T':
                        {
                            res[i] = 'A';
                            break;
                        }
                    case 'A':
                        {
                            res[i] = 'U';
                            break;
                        }
                    default:
                        {
                            free(res);
                            res = NULL;
                            invalid_dna_code = true;
                            break;
                        }
                }

                if(true == invalid_dna_code)
                {
                    break;
                }
            }
        }
    }

    return res;
}
