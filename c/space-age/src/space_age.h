/*
 * space_age.h
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>
#include <float.h>

typedef enum
{
    EARTH = 0,
    MERCURY = 1,
    VENUS = 2,
    MARS = 3,
    JUPITER = 4,
    SATURN = 5,
    URANUS = 6,
    NEPTUNE = 7,
    PLANET_MAX = 8
} planet_t_;

float convert_planet_age(planet_t_ planet, uint64_t seconds);

#endif /* !SPACE_AGE_H */
