/*
 * anagram.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "anagram.h"

/**
 * @brief Determines if any of the words in the candidate 
 *        are anagrams for word.
 * 
 * @param word          reference word
 * @param candidates    list of canditates to be examined
 */
void anagrams_for(const char *word, struct candidates *candidates)
{
    if(NULL != word)
    {
        uint8_t word_len = strlen(word);
        char * word_cp = calloc(word_len, sizeof(char));

        for(uint8_t c = 0U; c < candidates->count; c++)
        {
            if(NULL == candidates->candidate[c].candidate)
            {
                candidates->candidate[c].is_anagram = NOT_ANAGRAM;
            }
            else if(strlen(candidates->candidate[c].candidate) != word_len)
            {
                candidates->candidate[c].is_anagram = NOT_ANAGRAM;
            }
            else if(0 == strcasecmp(word, candidates->candidate[c].candidate))
            {
                candidates->candidate[c].is_anagram = NOT_ANAGRAM;
            }
            else
            {
                memcpy(word_cp, word, word_len);
                candidates->candidate[c].is_anagram = IS_ANAGRAM;
                for(uint8_t cc = 0; cc < word_len; cc++)
                {
                    bool found_char = false;
                    for(uint8_t wc = 0; wc < word_len; wc++)
                    {
                        if(tolower(candidates->candidate[c].candidate[cc]) == 
                            tolower(word_cp[wc]))
                        {
                            found_char = true;
                            word_cp[wc] = 0;
                            break;
                        }
                    }

                    if(false == found_char)
                    {
                        candidates->candidate[c].is_anagram = NOT_ANAGRAM;
                        break;
                    }
                }
            }
        }

        free(word_cp);
    }
}