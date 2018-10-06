/*
 * difference_of_squares.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>

#include "difference_of_squares.h"

static uint64_t sum(uint64_t num)
{
    return num ? (num + sum(num - 1)) : 0;
}

uint64_t square_of_sum(uint64_t num)
{
    uint64_t s = sum(num);
    return s*s;
}

uint64_t sum_of_squares(uint64_t num)
{
    return num ? (num*num + sum_of_squares(num - 1)) : 0;
}

uint64_t difference_of_squares(uint64_t num)
{
    return abs(square_of_sum(num) - sum_of_squares(num));
}
