/*
 * space_age.c
 * Copyright (C) 2018 Damian Ciecinski <damianciecinski@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "space_age.h"

#define EARTH_SECONDS (31557600U)

static const float earth_years[PLANET_MAX] =
{
    1.0f,           /* EARTH */
    0.2408467f,     /* MERCURY */
    0.61519726f,    /* VENUS */
    1.8808158f,     /* MARS */
    11.862615f,     /* JUPITER */
    29.447498f,     /* SATURN */
    84.016846f,     /* URANUS */
    164.79132f      /* NEPTUNE */
};


/**
 * @brief Calculate how old someone wolud be on specific planet.
 *
 * @param planet kind of planet
 * @param seconds age in seconds
 *
 * @return age on specific planet
 */
float convert_planet_age(planet_t_ planet, uint64_t seconds)
{
    return seconds/(earth_years[planet]*EARTH_SECONDS);
}

