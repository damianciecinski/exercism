/*
 * binary_search.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include <stdint.h>
#include <stddef.h>

#include "binary_search.h"

/**
 * @brief Search number in array using binary search algorithm.
 *
 * @param number    search number
 * @param array     array to be searched
 * @param length    length of array
 *
 * @return pointer (within array) to found number or NULL
 */
const int * binary_search(int number, const int * array, int length)
{
    if(NULL != array && length > 0)
    {
        int32_t lowIdx = 0, centerIdx = 0, highIdx = length - 1;
        while(lowIdx <= highIdx)
        {
            centerIdx = lowIdx + ((highIdx - lowIdx) >> 1);
            if(array[centerIdx] == number)
            {
                return &array[centerIdx];
            }

            if(array[centerIdx] < number)
            {
                lowIdx = centerIdx + 1;
            }
            else
            {
                highIdx = centerIdx - 1;
            }
        }
    }

    return NULL;
}