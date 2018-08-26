/*
 * leap.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "leap.h"

/**
 * @brief Check if given year is a leap year.
 *
 * @param year year to investigate
 *
 * @return TRUE or FALSE
 */
bool is_leap_year(uint16_t year)
{
    return ((year % 4) == 0) && ((year % 100) != 0 || (year % 400) == 0);
}
