/*
 * word_count.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "word_count.h"

void add_word_to_list(char * word, word_count_word_t * words, int * unique_words_counter);

/**
 * @brief Search single words in passed text
 *
 * @param input_text text to parse
 * @param words list of words
 *
 * @return number of unique words
 */
int word_count(const char *input_text, word_count_word_t * words)
{ 
    /* clear list of words */
    memset(words, 0, sizeof(*words)*MAX_WORDS);
  
    char word[MAX_WORD_LENGTH + 1] = {0};
    uint8_t char_counter = 0;
    int res= 0;
    uint16_t len = strlen(input_text);

    for(uint16_t c = 0U; c < len; c++)
    {
        /* come accros char which is part of the word */
        if(isalpha(input_text[c]) || isdigit(input_text[c]) || input_text[c] == '\'')
        {
            /* check if apostrophe is in the middle of word - only this 
             * situation is allowed (i.e. don't, I'm) */
            if((input_text[c] == '\'' && (c + 1) < len))
            {
                if(!((isalpha(input_text[c + 1]) || isdigit(input_text[c + 1])) && 
                            char_counter > 0))
                {
                    continue;
                }
            }
            
            /* check if word is not longer than allowed length */
            if(char_counter < MAX_WORD_LENGTH)
            {
                /* copy char of word to separate buffer */
                word[char_counter++] = tolower(input_text[c]);
            }
            else
            {
                res = EXCESSIVE_LENGTH_WORD;
                break;
            }            
        }
        else
        {
            /* come across char which is not digit, alpha or apostrophe 
             * what means that it is the end of the word */
            if(char_counter > 0)
            {
                word[char_counter] = 0;
                add_word_to_list(word, words, &res);
                char_counter = 0;
            }
        }

        /* add last word to list */
        if(c == (len - 1) && char_counter > 0)
        {
            word[char_counter] = 0;
            add_word_to_list(word, words, &res);
        }
    }

    return res;
}

/**
 * @brief Add word to the list, if word is already added, only the counter is increased.
 *
 * @param word new word to add
 * @param words list of words
 * @param unique_words_counter number of unique words
 *
 */
void add_word_to_list(char * word, word_count_word_t * words, int * unique_words_counter)
{
    bool found_or_created_word = false;
    
    for(uint8_t w = 0; w < MAX_WORDS ; w++)
    {
        /* search first empty position in buffer */
        if(words[w].count == 0)
        {
            /* add new word to the list */
            words[w].count++;
            strcpy(words[w].text, word);
            (*unique_words_counter)++;
            found_or_created_word = true;
            break;
        }
        else
        {
            /* compare word with words in the list */
            if(strcmp(word, words[w].text) == 0)
            {
                /* increment counter and break from loop */
                found_or_created_word = true;
                words[w].count++;
                break;
            }
        }
    }

    /* if word was not found or created, it means that list is full */
    if(false == found_or_created_word)
    {
        *unique_words_counter = EXCESSIVE_NUMBER_OF_WORDS; 
    }
}
