/*
 * roman_numerals.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "roman_numerals.h"

typedef struct 
{
    uint16_t normal_number;
    char * roman_numeral;
} rom_num_mapping_t;

static const rom_num_mapping_t rom_num_mapping[] = 
{
    {1000,  "M"},
    {900,  "CM"},
    {500,   "D"},
    {400,  "CD"},
    {100,   "C"},
    {90,   "XC"},
    {50,    "L"},
    {40,   "XL"},
    {10,    "X"},
    {9,    "IX"},
    {5,     "V"},
    {4,    "IV"},
    {1,     "I"}
};

#define ROM_NUM_MAPPING_SIZE (sizeof(rom_num_mapping)/sizeof(rom_num_mapping[0]))

/**
 * @brief Converts number to roman numerals.
 *
 * @param number    number to be converted
 *
 * @return pointer to roman numerals - has to be free
 */
char * to_roman_numeral(int number)
{
    char * ret = calloc(1, sizeof(char));
    uint8_t ret_counter = 0;
    for(uint8_t rs = 0; rs < ROM_NUM_MAPPING_SIZE; rs++)
    {
        uint8_t mul = number/rom_num_mapping[rs].normal_number;
        for(uint8_t m = 0; m < mul; m++)
        {
            uint8_t len = strlen(rom_num_mapping[rs].roman_numeral);
            ret = realloc(ret, ret_counter + len);
            strcpy(&ret[ret_counter], rom_num_mapping[rs].roman_numeral);
            ret_counter += len;
        }
        number %= (rom_num_mapping[rs].normal_number);
    }

    ret[ret_counter] = 0;
    return ret;
}